#include <stdio.h>
#include <stdlib.h>

double Add(int i, int j);//function prototype for the addition

double Multiply(int i, int j);//function prototype for the multiplication

double Subtract(int i, int j);//function prototype for the subtraction

double Divide(int i, int j);//function prototype for the division

void Help(char op2);//function prototype for the Help command

char Quit(char op2);//function prototype for the Quit command


int main()
{
char op;//character for the initial letter name
char op1;//character for the initial letter last name
char op2;//character for the commands + - * /
char op3;
char op4 = 'n';
int i = 0;
int j = 0;
int result = 0;
double numb = 0;

FILE *myPointer;
FILE *myPointer2;

myPointer = fopen("CommandsProj1.dat", "r");
myPointer2 = fopen("CalcResults.dat","w");

if (myPointer != NULL){
    fscanf(myPointer,"%c%c",&op, &op1);
printf("===============================================================================\n");
printf("| =========================================================================== | ||");
printf("\t\t\t\t\t\t     \t                     ||\n");
printf("||     \t\t\t\t\t\t\t\t             ||\n||");
printf("\t\t\t\t\t\t     \t\t             ||\n||");
printf("\t\t\t\t\t\t\t\t             ||\n||");
printf("                        Welcome to %c%c Calculator         \t\t     ||\n||\n||", op, op1);
printf("                From the developers of the CFE-2013 Series...\n\n");
printf("\n      *******************************************************************");
printf("\n\n         The  %c%c  calculator reads and extracts ", op, op1);
printf(" data and the commands \n         -- '+', '-', '*', and '/'-- ");
printf("  from the file CommandsProj1.dat \n       ");
printf("  to be  processed  sequentially,  performing the ");
printf(" calculations \n         and  printing  them  out ");
printf("in  CalcResults.dat and the display.\n\n       ");
printf("  The command Help will explain in detail the functions to be\n");
printf("                        performed by this calculator.\n\n");
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
fprintf(myPointer2, "\n\n         The  %c%c  calculator reads and extracts ", op, op1);
fprintf(myPointer2, " data and the commands \n         -- '+', '-', '*', and '/'-- ");
fprintf(myPointer2, "  from the file CommandsProj1.dat \n       ");
fprintf(myPointer2, "  to be  processed  sequentially,  performing the ");
fprintf(myPointer2, " calculations \n         and  printing  them  out ");
fprintf(myPointer2, "in  CalcResults.dat and the display.\n\n       ");
fprintf(myPointer2, "  The command Help will explain in detail the functions to be\n");
fprintf(myPointer2, "                        performed by this calculator.\n\n");
fprintf(myPointer2, "   ===========================================================================\n");

do{
    fscanf(myPointer,"%c ", &op2);

    if (op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' ){
            fscanf(myPointer, " %d", &i);
            fscanf(myPointer, " %d", &j);
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

    //case substraction:
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

    //Help case
    case 'H' :
    printf("\n\nHelp command will explain all the functions that this calculator does.\n\n");
    fprintf(myPointer2, "Help command will explain all the functions that this calculator does.\n\n");

    fprintf(myPointer2, " + [Integer Add]\t\tAdd integers i and j and print out result\n\n");
    fprintf(myPointer2, " * [Integer Multiply]\tMultiply integers i and j and print out result\n\n");
    fprintf(myPointer2, " - [Integer Subtract ]\tSubtract integer j from i and print out result\n\n");
    fprintf(myPointer2, " / [Integer Divide ]\t\t Divide integer i by j and print out result of\n\t\t\t\tinteger division\n\n");
    fprintf(myPointer2, " H [Help ]\t\tPrint a short synopsis of all the available\n\t\t\t\tcommands\n\n");
    fprintf(myPointer2, " Q [Quit ]\t\tQuit\n\n");

    Help(op2);

    break;

    //case quit
    case 'Q' :

    fprintf(myPointer2, "Is it your desire to quit? Type y (yes) or n (no): ");
    printf("\n\nyou have chosen %c ", Quit(op4));
    fprintf(myPointer2, "\nyou have chosen %c ", Quit(op4));
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

if(op4 == 'y'){
fclose(myPointer);//close the file where the commands are read from.
fclose(myPointer2);//close the file where the print out was done.

    return 0;
}
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

double Divide(int i, int j){//body of the function of the operand division

    return i/j;
}

void Help(char op2){//Help command will explain all the functions that this calculator does
    printf("\n\nThis are the calculator commands:\n\n");
    printf("+ [Integer Add]\t\tAdd integers i and j and print out result\n\n");
    printf("* [Integer Multiply]\tMultiply integers i and j and print out result\n\n");
    printf("- [Integer Subtract ]\tSubtract integer j from i and print out result\n\n");
    printf("/ [Integer Divide ]\t\tDivide integer i by j and print out result of\n\t\t\t\tinteger division\n\n");
    printf("H [Help ]\t\t\tPrint a short synopsis of all the available\n\t\t\t\tcommands\n\n");
    printf("Q [Quit ]\t\t\tQuit\n\n");


}

char Quit(char op4){//The user will be asked to quit or to continue

    printf("\n\nIs it your desire to quit? Type y (yes) or n (no): ");
    scanf(" %c", &op4);

    return op4;

}


