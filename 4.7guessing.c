/* Program 4.7A		A More Interesting Guessing Game	*/
#include <stdio.h>
#include <stdlib.h>			    /* for rand() and srand() */
#include <time.h>				  /* for time() function */

void tolowhi(int c, int g);

int main (void)
{
	char play = 'Y';
	int chosen = 0;					/* the Lucky number */
	int guess = 0;						/* stores the guess */
	int count = 3;					 /* the max num of tries */
	int limit = 20;	/* Upper limit for pseudo-random values */

	srand(time(NULL));	    /* use clock value as starting seed */

	while(play=='Y'||play=='y')
	{
	 count = 3;
	 chosen = 1 + rand()%limit;		/* random int 1 to limit */

	 puts("\nThis is a guessing game");
	 puts("I have chosen a number 1 through 20 which you must guess");

	 for( ; count>0; --count)
	 {
	  printf("You have %d tr%s left.", count, count==1? "y" : "ies");
	  printf("\nEnter your guess: ");			/* prompt for a guess */
	  scanf("%d", &guess);					   /* read in a guess */

	  /* Check for a correct guess */
	  if(guess == chosen)
	  {
	   puts("\nYou guessed it!");
	   /* system("PAUSE"); <-dos command*/
	   return 0;
	  }/* END THE PROGRAM */

	  /* Check for an invalid guess */
	  if(guess<1 || guess>20)
		puts("I said between 1 and 20.");
	  else
        tolowhi(chosen, guess);
		/*printf("Sorry. %d is wrong.", guess);*/
	 }/*endfor*/
	 printf("\nYou have had three tries and failed. The number was %d\n", chosen);
	 printf("Would you like to play again? (y/n) ");/*XXX **TODO: Fix always quits */
	 scanf("%c", &play);
	 fflush(stdin);
	}
	/* system("PAUSE"); <-dos command */
	return 0;
}
void tolowhi(int c, int g)
{
    if(g > c)printf("Sorry. %d is too high.", g);
    else printf("Sorry. %d is too low.", g);
}
