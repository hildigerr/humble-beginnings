/*
    2-dice
    aim: reach 1000
    start: 0
    roll 2 dice
    you decide which is the # and which is the operator
        1-add
        2-subtract
        3-multiply
        4-divide
        5-add
        6-multiply
*/

#include <stdio.h>

int die1,
    die2,
    opp;
float number =0;

void roll(void);
int oppic(void);
void useop( int opp );

int main()
{
    srand(time());

    system("clear");/*dos use ->"cls");*/
    puts("1000");
    puts("The aim is to reach the number 1000 -no more no less- as quickly as possible.");
    puts("You will get two random numbers 1-6.");
    puts("You decide which one of them will be used to determine which opperator to use,");
    puts("\n#\toperation\n");
    puts("1\tadd\n2\tsubtract\n3\tmultiply\n4\tdivide\n5\tadd\n6\tmultiply\n");
    /*system("PAUSE");*/

    while(number != 1000)
    {
        printf("\nNUMBER = %.2f\t", number);
        roll();
        printf("DICE = %d  %d\n\n", die1, die2);
        useop(oppic());
    }

    /*system("PAUSE");*/
    return 0;
}
void roll(void)
{
    die1 = (rand() % 6) +1;
    die2 = (rand() % 6) +1;
}
int oppic( void )
{
    opp = 0;

    printf("Do you want to  1: ");
    switch(die1)
    {
     case 1:
        printf("add %d or ", die2);
        break;
     case 2:
        printf("subtract %d or ", die2);
        break;
     case 3:
        printf("multiply %d or ", die2);
        break;
     case 4:
        printf("divide %d or ", die2);
        break;
     case 5:
        printf("add %d or ", die2);
        break;
     case 6:
        printf("multiply %d or ", die2);
        break;
    }

    printf("\n\t\t2: ");
    switch(die2)
    {
     case 1:
        printf("add %d? ", die1);
        break;
     case 2:
        printf("subtract %d? ", die1);
        break;
     case 3:
        printf("mulitply %d? ", die1);
        break;
     case 4:
        printf("divide %d? ", die1);
        break;
     case 5:
        printf("add %d? ", die1);
        break;
     case 6:
        printf("multiply %d? ", die1);
        break;
    }

    printf("\n\t\t0: quit.\n->");

    
    do{
        scanf("%d", &opp);
    }while(opp != 0 && opp != 1 && opp !=2);

    return opp;
}
void useop ( int opp )
{
    switch( opp )
    {
     case 0:
        number = 1000;
        break;
     case 1:
        switch ( die1 )
        {
         case 1:
            number += die2;
            break;
         case 2:
            number -= die2;
            break;
         case 3:
            number *= die2;
            break;
         case 4:
            number /= die2;
            break;
         case 5:
            number += die2;
            break;
         case 6:
            number *= die2;
            break;
        }/*end die1 switch*/
     case 2:
     {
        switch ( die2 )
        {
         case 1:
            number += die1;
            break;
         case 2:
            number -= die1;
            break;
         case 3:
            number *= die1;
            break;
         case 4:
            number /= die1;
            break;
         case 5:
            number += die1;
            break;
         case 6:
            number *= die1;
            break;
        }/*end die2 switch*/
     }/*end case 2*/
    }/*end opp switch*/
}
