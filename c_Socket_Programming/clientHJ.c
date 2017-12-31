#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORTNO 30000

void error(char *msg)
{
	perror(msg);
	exit(1);
}

/*
Reference
struct  hostent
{
  char    *h_name;        // official name of host
  char    **h_aliases;    // alias list
  int     h_addrtype;     // host address type
  int     h_length;       // length of address
  char    **h_addr_list;  // list of addresses from name server
  #define h_addr  h_addr_list[0]  // address, for backward compatiblity
};
*/

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
	if(argc<3){
		fprintf(stderr,"usage %s hostname port [own letter][other node letter]*\n", argv[0]);
		exit(0);
	}
	portno=atoi(argv[2]);
	sockfd=socket(AF_INET, SOCK_STREAM, 0); //Configure connection type
	if(sockfd<0)
		error("ERROR opening socket");
	server=gethostbyname(argv[1]); //find host by a name
	if (server==NULL){
		fprintf(stderr,"ERROR opening socket");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr)); //set to zero all the sockaddr_in struct
	serv_addr.sin_family=AF_INET; //mandatory set
	bcopy((char *)server->h_addr,
			(char *)&serv_addr.sin_addr.s_addr,
			server->h_length); //sets server address
	serv_addr.sin_port=htons(PORTNO); //set port converted to network byte order
	if(connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) //tries to connect to the server
		error("ERROR connecting");
			
	bzero(buffer,256); //cleans buffer again
	buffer[2] = argv[3][0];
	printf("Connecting to server...\n");
	if(argc < 5){
		buffer[0] = 0;
		n=write(sockfd,buffer,3); //sends the message through the socket
		if(n<0)
			error("ERROR writing to socket");
		printf("Connection succeeded. Waiting for other client.\n");
	}
	else{
		buffer[0] = 1;
		buffer[1] = argv[4][0];
		n=write(sockfd,buffer,3); //sends the message through the socket
		if(n<0)
			error("ERROR writing to socket");
	}	
	
	n=read(sockfd,buffer,255); //reads confirmation from the server
	if(n<0)
		error("ERROR reading from socket");

	if(buffer[0] == '*') { // Sentinel	
		int i;
		for(i=0; i<256; i++){
			buffer[i] = buffer[i+1];
		}
		printf("%s\n",buffer);
		return 0;
	}
					
	printf("%s\n",buffer);	
	char otherNode = buffer[21];
	
	if(argc < 5){		
		printf("Waiting for the message from %c\n",otherNode);		
		n=read(sockfd,buffer,255); //reads first message from other node
		if(n<0)
			error("ERROR reading from socket");
		printf("%s\n",buffer);
	}
	while(buffer[0] != '*') {// Sentinel		
		printf("Please enter the message (* at the first position of the message to close connection): ");
		bzero(buffer, 256); //set to zero the buffer where the message will be written
		fgets(buffer,255,stdin); //sets the input in the buffer
		n=write(sockfd,buffer,strlen(buffer)); //sends the message through the socket
		if(n<0)
			error("ERROR writing to socket");
			
		if(buffer[0] != '*'){	//Sentinel
			bzero(buffer,256); //cleans buffer again
			printf("Waiting for the message from %c\n",otherNode);		
			n=read(sockfd,buffer,255); //reads the answer from the server
			if(n<0)
				error("ERROR reading from socket");				
			printf("%s\n",buffer);
		}
	}
	printf("The connection was closed by %c. Closing...\n",argv[3][0]);	
	close(sockfd);
	return 0;
}
