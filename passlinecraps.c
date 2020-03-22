/* /Projects/port/REDO/passlinecraps.c */
/* Todo: check variable scope, ?re-package functions, REDO */

#include <stdio.h>

/*variables*/
int dice_tally =0;
int point =0;
int roll_qt =1;
float cash =0.25;
float bet =0;
float inc =-1;

/*prototypes*/
void fst_roll(void);
void snd_roll(void);
int main(void);
void sys_pause(void);
void myflush ( FILE *in );

int main( void )
{
	int dice_1 =0;
	int dice_2 =0;
	srand(time());
	cash += (rand() % 50) + 1;

	printf("\t*=================*\n");
	printf("\t|      CRAPS      |\n");
	printf("\t|       by        |\n");
	printf("\t|     HildigerR   |\n");
	printf("\t*=================*\n");
	/*system("PAUSE");<-dos command | for linux ->*/ sys_pause();

	while(cash > 0 || roll_qt == 2)
	{
	 /*start*/
	 printf("Current Cash = $%.2f\n", cash);

	 /*bets*/
	 while((bet > cash || bet <= 0) && roll_qt == 1)
	 {
	  printf("Enter bet: ");
	  scanf("%f", &bet);
	 }
	 while((inc > cash || inc < 0) && (roll_qt == 2 && cash > 0))
	 {
	  printf("Current Bet = $%.2f\n", bet);
	  printf("Enter bet increase if any: ");
	  scanf("%f", &inc);
	 }
	 if(roll_qt == 1) { cash -= bet; }
	 if(roll_qt == 2)
	 {
	  if (inc >= 0)
	  {
	   cash -= inc;
	   bet += inc;
	   inc = -1;
	  }
	  printf("\nBet Total = $%.2f\n\n", bet);
	 }/*end if roll_qt = 2*/

	 /*roll*/
	 if(roll_qt == 1) puts("\nCOME-OUT ROLL");
	 else puts("POINT ROLL");
	 dice_1 = (rand() % 6) +1;
	 dice_2 = (rand() % 6) +1;
	 printf("***\t***\n");
	 printf("*%d*\t*%d*\n", dice_1, dice_2);
	 printf("***\t***\n");
	 dice_tally = dice_1 + dice_2;

	 /*win checks*/
	 switch (roll_qt)
	 {
		case 1:
			fst_roll();
			break;
		case 2:
			snd_roll();
			break;
	 }/*end roll_qt switch*/

	}/*end play while*/
	/*system("PAUSE");<-dos command | for linux ->*/sys_pause();
	return 0;
}/*end main*/
void fst_roll(void)
{
	/*system("PAUSE");<-dos command | for linux ->*/sys_pause();
	switch(dice_tally)
	{
	 case 7: case 11:
	  printf("==============================\n\n");
	  puts("NATURALS!");
	  puts("We have a front line winner!");
	  puts("WINNINGS\tTOTAL");
	  cash += bet*2;
	  printf("$%.2f\t\t$%.2f\n\n", bet*2, cash);
	  printf("==============================\n\n");
	  bet = 0;
	  break;
	 case 2:
	  printf("==============================\n\n");
	  puts("SNAKE EYES!");
	  puts("Two craps aces, the line falls!");
	  puts("LOSS\tTOTAL");
	  printf("$%.2f\t$%.2f\n\n", bet, cash);
	  printf("==============================\n\n");
	  bet = 0;
	  break;
	 case 3: case 12:
	  printf("==============================\n\n");
	  puts("CRAPS ROLL!");
	  puts("LOSS\tTOTAL");
	  printf("$%.2f\t$%.2f\n\n", bet, cash);
	  printf("==============================\n\n");
	  bet =0;
	  break;
	 default:
	  point = dice_tally;
	  printf("Point of %d\n", point);
	  roll_qt = 2;
	}
}/*end fst_roll*/
void snd_roll(void)
{
	/*system("PAUSE");<-dos command | for linux ->*/sys_pause();
	switch(dice_tally)
	{
	 case 7:
	  printf("==============================\n\n");
	  puts("7-Out line away!");
	  puts("LOSS\tTOTAL");
	  printf("$%.2f\t$%.2f\n\n", bet, cash);
	  printf("==============================\n\n");
	  roll_qt = 1;		/* reset rolls */
	  bet = 0;		/* reset bets  */
	  break;
	 case 2: case 3: case 4: case 5: case 6: case 8:
     case 9: case 10: case 11: case 12:
	  if(dice_tally == point)
	  {
		printf("==============================\n\n");
		printf("POINT %d WIN!\n", point);
		puts("WINNINGS\tTOTAL");
		cash += bet*2;
		printf("$%.2f\t\t$%.2f\n\n", bet*2, cash);
		printf("==============================\n\n");
		roll_qt = 1;		/* reset rolls */
		bet = 0;			/* reset bets	*/
		break;
	  }
	 default:
		puts("Roll again...");
	}
}/*end snd_roll*/
void sys_pause(void)
{
    myflush(stdin);
	puts("Press Enter to continue...");
	fflush(stdout);
	getchar();
}
void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in ); 
  while ( ch != EOF && ch != '\n' ); 

  clearerr ( in );
}
