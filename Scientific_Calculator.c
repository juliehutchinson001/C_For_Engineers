#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

double Add(int i, int j);//function prototype for the addition command

double Multiply(int i, int j);//function prototype for the multiplication command

double Subtract(int i, int j);//function prototype for the subtraction command

double Divide(int i, int j);//function prototype for the division command

void Help(char op2);//function prototype for the Help command

int main()//initializing main function
{
char op;//character for the initial name letter
char op1;//character for the initial last name letter
char op2;//character for the commands
char op3;//character for the lowercase uppercase command
char op5;//character for the P command
char sign;//defines the + or - of the number when being separated
char arr[70];//array to locate the kth digit of the number
int i = 0;//main numbers to be scanned
int j = 0;//main numbers to be scanned
float numb2;
float numb = 0;
float decimal = 0;
int intPart = 0;
int fraction = 0;
int k = 0;
int ch1 = 0;
int ch2 = 0;

FILE *myPointer;//creating pointer for reading
FILE *myPointer2;//creating pointer for writing

myPointer = fopen("CommandsProj2.dat", "r");//opening the file for reading purposes
myPointer2 = fopen("Results.dat","w");//opening the file to print out the results

if (myPointer != NULL){
    fscanf(myPointer,"%c%c",&op, &op1);
printf("===============================================================================\n");
printf("| =========================================================================== | ||");
printf("\t\t\t\t\t\t     \t                     ||\n");//Explanations of the  calculator functions
printf("||     \t\t\t\t\t\t\t\t             ||\n||");
printf("\t\t\t\t\t\t     \t\t             ||\n||");
printf("\t\t\t\t\t\t\t\t             ||\n||");
printf("                        Welcome to %c%c Calculator         \t\t     ||\n||\n||", op, op1);
printf("                From the developers of the CFE-2013 Series...\n\n");
printf("\n      *******************************************************************");
printf("\n\n       The  %c%c  calculator reads and extracts ", op, op1);
printf(" data and the commands --\n       '+', '-', '*', '/', 'P', 'R', 'S', 'D', 'C', 'c' and 'Q'-- ");
printf(" from\n       the  file  CommandsProj1.dat ");
printf(" to  be  processed  sequentially,\n      performing the ");
printf("calculations and printing them out ");
printf("in CalcResults.dat \n                           and the display.\n\n       ");
printf("    The command Help will explain in detail the functions to be");
printf("\n                            performed by this calculator.\n\n");
printf("      *******************************************************************\n");

fprintf(myPointer2, "===============================================================================\n");
fprintf(myPointer2, "| =========================================================================== | ");
fprintf(myPointer2, "\t\t\t\t\t\t     \t                     \n");
fprintf(myPointer2, "||     \t\t\t\t\t\t\t\t             ||\n||");
fprintf(myPointer2, "\t\t\t\t\t\t     \t\t             ||\n||");
fprintf(myPointer2, "\t\t\t\t\t\t\t\t             ||\n||");
fprintf(myPointer2, "                        Welcome to %c%c Calculator         \t\t     ||\n||\n||", op, op1);
fprintf(myPointer2, "                From the developers of the CFE-2013 Series...\n\n");
fprintf(myPointer2, "\n      *******************************************************************");
fprintf(myPointer2, "\n\n       The  %c%c  calculator reads and extracts ", op, op1);
fprintf(myPointer2, "data and the commands --\n       '+', '-', '*', '/', 'P', 'R', 'S', 'D', 'C', 'c' and 'Q'-- ");
fprintf(myPointer2, " from\n       the  file  CommandsProj1.dat ");
fprintf(myPointer2, " to  be  processed  sequentially,\n      performing the ");
fprintf(myPointer2, "calculations and printing them out ");
fprintf(myPointer2, "in CalcResults.dat \n                           and the display.\n\n       ");
fprintf(myPointer2, "    The command Help will explain in detail the functions to be");
fprintf(myPointer2, "\n                            performed by this calculator.\n\n");

do{
    fscanf(myPointer,"%c ", &op2);


    if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/'){
        fscanf(myPointer, "%d ", &i);
        fscanf(myPointer, "%d", &j);

        if(op2 == 'C' || op2 == 'c'){
                fscanf(myPointer, " %c", &op3);
        }
    }// end if

switch (op2)
    {

    //case addition :
    case '+':
    printf("\nThis function solves the addition operation: \n");
    fprintf(myPointer2, "\nThis function solves the addition operation: \n");
    printf("%d + %d = %.1f\n\n", i, j, Add(i, j));
    fprintf(myPointer2,"%d + %d = %.1f\n\n",i, j, Add(i, j));
    break;

    //case subtraction:
    case '-' :
    printf("This function solves the subtraction operation: \n");
    fprintf(myPointer2, "This function solves the subtraction operation: \n");
    printf("%d - %d = %.1f\n\n",i, j, Subtract(i, j));
    fprintf(myPointer2,"%d - %d = %.1f\n\n",i, j, Subtract(i, j));
    break;

    //case multiplication
    case '*' :
    printf("This function solves the multiplication operation: \n");
    fprintf(myPointer2, "This function solves the multiplication operation: \n");
    printf("%d * %d = %.1f\n\n",i, j, Multiply(i, j));
    fprintf(myPointer2,"%d * %d = %.1f\n\n",i, j, Multiply( i, j));
    break;

    //case division
    case '/' :
    printf("This function solves the division operation: \n");
    fprintf(myPointer2, "This function solves the division operation: \n");
    printf("%d / %d = %.2f\n\n",i, j, Divide(i, j));
    fprintf(myPointer2,"%d * %d = %.2f\n\n",i, j, Divide( i, j));
    break;

    //rounding case
    case 'R' :
    fscanf(myPointer, "%f %f", &decimal, &numb2);
    numb = decimal * (pow(10.0, numb2-1));
    numb = floor(numb + 0.5);
    numb = numb / (pow(10.0, numb2-1));

    printf("The following function will round a value x to i decimal places:\n");
    printf("%f rounded to %.0f decimal places is %f\n\n", decimal, numb2, numb);
    fprintf( myPointer2, "The following function will round a value x to i decimal places:\n");
    fprintf( myPointer2, "%f rounded to %.0f decimal places is %f\n\n", decimal, numb2, numb);

    break;

    //separation case
    case 'S' :
    fscanf(myPointer, " %d.%d", &intPart, &fraction);
    if(intPart > 0){
        sign = '+';
    }
    else{
        sign = '-';
        intPart = -1 * intPart;
        }
    printf("\nThe following function will separate a number from its sign, integer part\n and decimal part:\n");
    fprintf(myPointer2, "\nThe following function will separate a number from its sign, integer part\n and decimal part:\n");
    printf("%d.%d ==>  sign = %c, integer = %d,fraction = %d\n", intPart, fraction, sign,intPart,fraction);
    fprintf( myPointer2, "%d.%d ==>  sign = %c, integer = %d, fraction = %d\n\n", intPart, fraction, sign, intPart, fraction);

    break;

    //k-th digit of the number
    case 'P':
    j = 0;
    //fscanf(myPointer, "%c", &op5);
    do{
    fscanf(myPointer, "%c", &op5);
    arr[j] = op5;
    j++;
    }while(op5 != ' ');

    fscanf(myPointer, "%d", &j);

    printf("\nThe following function will print out the k-th digit of integer i:\n");
    printf("\nPosition  %d of the number %d is %c\n\n", j, atoi(arr), arr[j - 1]);
    fprintf(myPointer2, "\nThe following function will print out the k-th digit of integer i:\n");
    fprintf(myPointer2, "\nPosition  %d of the number %d is %c\n\n", j, atoi(arr), arr[j - 1]);
    break;

    //partition of a number case
    case 'D':
    numb = floor(j * i/100.0);
    k = i - numb;

    printf("\n\nThe following function will find the partition of a number\n");
    fprintf(myPointer2, "\nThe following function will find the partition of a number\n\n");
    printf("i = %d, j = %d ==>  x = %.0f, k = %.0f \n\n", i, j, numb, decimal);
    fprintf(myPointer2, "i=%d,x=%d ==>  j=.0f, k=%.0f \n\n", i, j, numb, decimal);
    break;

    case 'c':
    printf("The following function will change a Capital letter into a lowercase letter\n");
    fprintf(myPointer2, "The following function will change a Capital letter into a lowercase letter\n");
    printf("%c ==> %c\n\n", op3,tolower(op3));
    fprintf( myPointer2, "%c ==> %c\n\n",op3,tolower(op3));
    break;

    case 'C':
    printf("The following function will change a lowercase letter into a capital letter\n");
    fprintf(myPointer2, "The following function will change a lowercase letter into a capital letter\n");
    printf("%c ==> %c\n", op3,toupper(op3));
    fprintf( myPointer2, "%c ==> %c\n\n",op3,toupper(op3));
    break;

    //Help case
    case 'H' :
    fprintf(myPointer2, "\n \t\t\t\t*** Help Menu! See below for Calculator Commands: ***\n");
    fprintf(myPointer2, "\n\t + i j ---> Add integers i and j. \n");
    fprintf(myPointer2, "\n\t * i j ---> Multiply integers i and j. \n");
    fprintf(myPointer2, "\n\t - i j ---> Subtract integer j from i. \n");
    fprintf(myPointer2, "\n\t / i j ---> Divide integer i by j. \n");
    fprintf(myPointer2, "\n\t C Ch ---> Change character Ch to uppercase. \n");
    fprintf(myPointer2, "\n\t c Ch ---> Change character Ch to lowercase. \n");
    fprintf(myPointer2, "\n\t P i k ---> Print out the k-th digit of integer i. \n");
    fprintf(myPointer2, "\n\t R x i ---> Round double value x to i decimal places. \n");
    fprintf(myPointer2, "\n\t S x ---> Separate out the sign, integer part and fractional part \n\t  of double value x. \n");
    fprintf(myPointer2, "\n\t D i x ---> Given integers i and x, print out two integers j and k, \n\t    where the sum of j and k equals i, and when you take x'percent' \n\t    of i and truncate it you get j. \n");
    fprintf(myPointer2, "\n\t H ---> view all commands. \n");
    fprintf(myPointer2, "\n\t Q ---> Quit program.\n\n");

    Help(op2);

    break;

    //case quit
    case 'Q' :
    fclose(myPointer);//close the file where the commands are read from.
    fclose(myPointer2);//close the file where the print out was done.

    return 0;

    break;

    default :

    break;

    } // end switch loop of the calculator commands

    }while(op2 != 'Q');//the loop will end if the user decides to quit by choosing yes

}// end if statement

else{
    //This message will be print out if there is and error with the files
    printf("Error opening File: \n");
    printf("1. Check the location of the file to be read from.\n");
    printf("2. Verify you created the file.\n\n");

    printf("if none of the previous options can be applied,");
    printf("Contact the administrator.\n\n");
}//end of else function that verifies if the file was opened correctly

printf("\n\n===============================================================================\n");
fprintf(myPointer2, "===============================================================================\n");




}// end main

double Add(int i, int j){//body of the function of the operand addition

    return i + j;
}

double Multiply(int i, int j){//body of the function of the operand multiplication


    return i * j;
}

double Subtract(int i, int j){//body of the function of the operand subtracttion

    return i - j;
}

double Divide(int i,  int j){//body of the function of the operand division

    return i/j;
}

void Help(char op2){//Help command will explain all the functions that this calculator does
    printf("\n\t\t *** Help Menu! See below for Calculator Commands: ***\n");
    printf("\n\t + i j ---> Add integers i and j. \n");
    printf("\n\t * i j ---> Multiply integers i and j. \n");
    printf("\n\t - i j ---> Subtract integer j from i. \n");
    printf("\n\t / i j ---> Divide integer i by j. \n");
    printf("\n\t C Ch ---> Change character Ch to uppercase. \n");
    printf("\n\t c Ch ---> Change character Ch to lowercase. \n");
    printf("\n\t P i k ---> Print out the k-th digit of integer i. \n");
    printf("\n\t R x i ---> Round double value x to i decimal places. \n");
    printf("\n\t S x ---> Separate out the sign, integer part and fractional part \n\t  of double value x. \n");
    printf("\n\t D i x ---> Given integers i and x, print out two integers j and k, \n\t    where the sum of j and k equals i, and when you take x'percent' \n\t    of i and truncate it you get j. \n");
    printf("\n\t H ---> view all commands. \n");
    printf("\n\t Q ---> Quit program.\n\n");
}


