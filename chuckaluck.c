
#include <stdio.h>

void instruct( void );
int bet_spec(int tp);
float single(int go, float amount);
float p_total(int go, float amount);
float high_low(int type, float amount);
float odd_even(int type, float amount);

int dice[4]; /*0-dice_1, 1-dice_2, 2-dice_3, 3-dice_total*/

int main()
{
    char yorn;
    float cash = .25;
    float bet_amount;
    int bet_type;
    int goal;

    /*get cash*/
    srand(time());
    cash += (rand() % 50) + 1;

    /*windows title
    printf("\t\t\b%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,
			   205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t%c   CHUCK-A-LUCK   %c\n", 186, 186);
    printf("\t%c        by        %c\n", 186, 186);
    printf("\t%c     Hildigerr    %c\n", 186, 186);
    printf("\t\t\b%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,
			   205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    system("PAUSE");
    */
    /*Linux Title*/
    printf("\t*------------------*\n");
    printf("\t|   CHUCK-A-LUCK   |\n");
    printf("\t|        by        |\n");
    printf("\t|     Hildigerr    |\n");
    printf("\t*------------------*\n");

    printf("\nDo you require instructions? (Y or N) ");
    scanf("%c", &yorn);
    if(yorn == 'y' || yorn == 'Y') instruct();

    while(cash > 0)
    {
        /*start*/
        puts("===========================================================");
        printf("\nCurrent Cash = $%.2f\n\n", cash);

        /*bet placement*/
        do{
           puts("What type of bet will you place?");
           puts("1-Single#, 2-Triple###, 3-Particular Total, 4-High(11-17),");
           printf("\t5-Low(4-10), 6-Odd, or 7-Even  :");
           scanf("%d", &bet_type);
        }while( bet_type < 1 || bet_type > 7 );
        if(bet_type == 1 || bet_type == 3) goal = bet_spec(bet_type);
        bet_amount = 0.00;
        do{
           printf("How much do you wish to bet? ");
           scanf("%f", &bet_amount);
        }while(bet_amount > cash);

        if(bet_amount == 0) break;  /*to quit*/

        /*roll dice*/
        dice[0] = (rand() %6) +1;
        dice[1] = (rand() %6) +1;
        dice[2] = (rand() %6) +1;
        dice[3] = dice[0] + dice[1] + dice[2];
        puts("===========================================================");
        printf("%d\t%d\t%d\n", dice[0], dice[1], dice[2]);

        switch(bet_type)
        {
            case 1:
                cash += single(goal, bet_amount);
                break;
            case 2:
                if((dice[0] == dice[1])&&(dice[1] == dice[2])) cash += bet_amount*30;
                else cash -= bet_amount;
                break;
            case 3: /*error doesnt always pay when win!*/
                cash += p_total(goal, bet_amount);
                break;
            case 4:
            case 5:
                cash += high_low(bet_type, bet_amount);
                break;
            case 6:
            case 7:
                cash += odd_even(bet_type, bet_amount);
        }/*end bet type switch*/
    }/*end while have cash*/

    /*system("PAUSE"); <-windows command*/
    return 0;
}
void instruct( void )
{
    int x;
    do{
       puts("\nThere are 7 kinds of bets:");
       puts("\t1-single, 2-triples, 3-total, 4-high, 5-low, 6-odd, 7-even");
       printf("Which one do you wish more info about? (1-7, 0 when done) :");
       scanf("%d", &x);

       switch(x){
            case 0: break;
            case 1:
                puts("\n\n\tSINGLE");
                puts("You coose a number 1-6. The 3 dice are rolled.");
                puts("If your number comes up");
                puts("                       once you get paid even money,");
                puts("                       twice you get double your money,");
                puts("                       thrice pays you triple.");
                break;
            case 2:
                puts("\n\n\tTRIPLES");
                puts("You bet that all three dice will be the same number.");
                puts("If you are correct you get paid 30 to 1!");
                break;
            case 3:
                puts("\n\n\tPARTICULAR TOTAL");
                puts("You choose a number 4-17. That is the dice total that");
                puts("must be rolled for you to be paid.");
                puts("But if a triple (also called a raffle) is rolled you loose.");
                break;
            case 4:
                puts("\n\n\tHIGH");
                puts("You bet that the total will be high, th.i. 11-17");
                puts("Pays even money. But you loose on a raffle.");
                break;
            case 5:
                puts("\n\nLOW");
                puts("You bet that the total will be low, th.i. 4-10");
                puts("Pays even money. But you loose on a raffle.");
                break;
            case 6:
                puts("\n\n\tODD");
                puts("You bet that the total will be odd.");
                puts("Pays even money. But you loose on a raffle.");
                break;
            case 7:
                puts("\n\n\tEVEN");
                puts("You bet that the total will be even.");
                puts("Pays even money. But you loose on a raffle.");
                break;
            default:
                puts("YOU MUST ENTER 0 to QUIT or 1-7 FOR INSTRUCTION");
            }
            /*if(x != 0) system("PAUSE");*/
    }while(x != 0);
}
int bet_spec(int tp)
{
    int r;
    do{
       printf("What number do you bet on? ");
       scanf("%d", &r);
    }while( (tp==1&&(r<1||r>6)) || (tp==3&&(r<4||r>17)) );
    return r;
}
float single(int go, float amount)
{
    int x;
    float ret =0.00;

    for(x=0; x<3; x++)
    {
        if(go == dice[x]) ret += amount;
    }
    if(ret == 0) ret -= amount;
    return ret;
}
float p_total(int go, float amount)
{
    if( dice[3] != go ) amount -= amount*2;
    else if( (dice[0] == dice[1])&&(dice[1] == dice[2]) ) amount -= amount*2;
    return amount;
}
float high_low(int type, float amount)
{
    if((type == 4)&&( dice[3] < 11 )) amount -= amount*2;
    else if((type == 5)&&(dice[3] > 10)) amount -= amount*2;
    else if((dice[0] == dice[1])&&(dice[1] == dice[2])) amount -= amount*2;
    return amount;
}
float odd_even(int type, float amount)
{
    if((type == 6)&&( dice[3] %2 == 0)) amount -= amount*2;
    else if((type == 7)&&( dice[3] %2 != 0)) amount -= amount*2;
    else if((dice[0] == dice[1])&&(dice[1] == dice[2])) amount -= amount *2;
    return amount;
}

