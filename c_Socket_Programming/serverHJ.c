/* A simple server in the internet domain using TCP
   The port number is passed as an argument 
   This version runs forever, forking off a separate 
   process for each connection
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 30000

char clients[10];
int nclients = 0;

void dostuff (int sock, char node, char otherNode, int pipein, int pipeout, int isfirstToWrite); /* function prototype */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
	 char clients[10];
	 int nclients = 0;
	 int pipes[10][2];
	 int mainpipe[10][2];
	 
	 //Set up the pipes
	 int i;
	 for(i=0; i<10; i++){ 
		 pipe(pipes[i]);
		 pipe(mainpipe[i]);
	 }
	 
     int sockfd, newsockfd, portno, pid;
     socklen_t clilen;
     struct sockaddr_in serv_addr, cli_addr;

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
        
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(PORTNO);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
	 char buffer[3];
	 
     while (1) {
         newsockfd = accept(sockfd, 
               (struct sockaddr *) &cli_addr, &clilen);
         if (newsockfd < 0) 
             error("ERROR on accept");
         pid = fork();
         if (pid < 0)
             error("ERROR on fork");
         if (pid == 0)  {	
			 int nclient = nclients++;
			 /* Parent process closes up output side of pipe */
			 close(pipes[nclient][1]);		 		     
			 close(mainpipe[nclient][0]);		 		     
             close(sockfd);
             
			 int n;
				  
			 bzero(buffer,3);
			 n = read(newsockfd,buffer,3);			 
			 if (n < 0) error("ERROR reading from socket");
			 
		     clients[nclient] = buffer[2];
			 if(buffer[0] == 0) {	
				 printf("Client %c connected\n",clients[nclient]);
				 
				/* Send id of the other node through the output side of the main pipe */
				buffer[0] = 1;
				buffer[1] = clients[nclient];
				write(mainpipe[nclient][1], buffer, 2);
				    
				 /* Read in a the id of the node connecting */
				 n = read(pipes[nclient][0], buffer, 2);
				 char otherNodeID = buffer[0];
				 printf("Other node id %i ", otherNodeID);
				 dostuff(newsockfd, clients[nclient], buffer[1], pipes[nclient][0], pipes[otherNodeID][1], 0);
			 }
			 else {
				 char j;
				 for(j=0; j<nclients; j++)
				 {
				    if(clients[j] == buffer[1])
			        {
				        break;
				    }
				 }
				 if(j < nclients)
				 {					 
					/* Send id of the other node through the output side of the main pipe */
					buffer[0] = 1;
					buffer[1] = clients[nclient];
					write(mainpipe[nclient][1], buffer, 2);
					
				    /* Send id of the other node through the output side of pipe */
				    buffer[0] = nclient;
				    write(pipes[j][1], buffer, 2);
					dostuff(newsockfd, clients[nclient], clients[j], pipes[nclient][0], pipes[j][1], 1);
				 }
				 else{								 
					printf("Node %c is asking for node %c, but is not connected. Closing the connection with %c\n",clients[nclient], buffer[1], clients[nclient]);
								 
					/* Send id of the other node through the output side of the main pipe */
					buffer[0] = -1;
					write(mainpipe[nclients][1], buffer, 2);
					
					char message[256];
					bzero(message,256);
					message[0] = '*'; //Sentinel
					strcat(message, "Node ");
					message[6] = buffer[1];
					strcat(message, " is not connected. Closing...\n");		 
				    n = write(newsockfd,message,strlen(message));
					if (n < 0) error("ERROR writing to socket");
				 }
			 }
             exit(0);
         }
         else {		   			 
			 close(mainpipe[nclients][1]);
			 /* Read in a the id of the node connecting */
			 bzero(buffer,3);  
			 
			 printf("reading from mainpipe...\n");
			 int n = read(mainpipe[nclients][0], buffer, 2);
			 printf("Buffer from mainpipe: %s\n", buffer);
			 
			 if(buffer[0] >= 0){
				clients[nclients++] = buffer[1];
				printf("Added connection to node %c to main thread\n",buffer[1]);
			 }
			 close(newsockfd);
		 }
     } /* end of while */
     close(sockfd);
     return 0; /* we never get here */
}

/******** DOSTUFF() *********************
 There is a separate instance of this function 
 for each connection.  It handles all communication
 once a connnection has been established.
 *****************************************/
void dostuff (int sock, char node, char otherNode, int pipein, int pipeout, int isfirstToWrite)
{
   int n;
   char buffer[256];
      
   char message[31];
   bzero(message, 31);
   strcpy(message, "Connection with node ");
   message[21] = otherNode;
   strcat(message, " is ready");
   
   n = write(sock, message, 31);
   
   bzero(buffer,256);
   if(isfirstToWrite == 0){
       printf("Reading from pipe %d of node %c ...\n",pipein, node);
	   /* Read in a string from the pipe */
       n = read(pipein, buffer, sizeof(buffer));
       
       printf("Here is the message from node %c (pipe): %s\n",otherNode,buffer);
	   n = write(sock, buffer, (strlen(buffer)+1));
	   if (n < 0) error("ERROR writing to socket");
   }   
   //Checking for sentinel
   while(buffer[0] != '*') {	   
	   bzero(buffer,256);
	   n = read(sock,buffer,255);
	   if (n < 0) error("ERROR reading from socket");
	   printf("Here is the message from node %c (socket): %s\n",node,buffer);
	   
	   /* Send "string" through the output side of pipe */
	   write(pipeout, buffer, sizeof(buffer));
	   
	   bzero(buffer,256);	   
       printf("Reading from pipe %d of node %c ...\n",pipein, node);
	   /* Read in a string from the pipe */
       n = read(pipein, buffer, sizeof(buffer));
       
       printf("Here is the response from node %c (pipe): %s\n",otherNode,buffer);
	   n = write(sock, buffer, (strlen(buffer)+1));
	   if (n < 0) error("ERROR writing to socket");
   }
}
