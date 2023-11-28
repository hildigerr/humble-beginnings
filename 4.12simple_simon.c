/* Program 4.12 Simple Simon */
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main (void)
{
	/* Records if another game is to be played */
	char another_game = 'Y';

	/* True if correct sequence entered, false otherwise */
	int correct = TRUE;

	/* Number of sequences entered successfully */
	int counter = 0;

	int sequence_length = 0;        /* Number of digits in a sequence */
	time_t seed = 0;	 	/* Seed value for random number sequence */
	int number = 0;                          /* Stores an input digit */
	int i = 1;

	time_t now = 0;	 /* Stores current time -- seed for random values */
	int time_taken = 0;				 /* Time taken for game in seconds */

	/* Describe how the game is played */
	printf("\nTo play Simple Simon, ");
	printf("watch the screen for a sequence of digits.");
	printf("\nWatch carefully, as the digits are only displayed "
							"for a second!");
	printf("\nThe computer will remove them, and then prompt you ");
	printf("to enter the same sequence.");
	printf("\nWhen you do, you must put spaces between the digits. \n");
	printf("\nGood Luck!\nPress Enter to play\n");
	scanf("%c", &another_game);

	/* One outer loop iteration is one game */
	do
	{
	 correct = TRUE;  	  /* by default indicates correct sequence entered */
	 counter = 0;		/* Initialize count of number of successfull tries */
	 sequence_length = 2;	   /* Initialize length of a digital sequence */
	 time_taken = clock();    	 /* record current time at start of game */

	 /* Inner loop continues as long as sequences are entered correctly*/
	 while(correct)
	 {
	  /* On every third successful try, increase the sequence length */
	  sequence_length += counter++%3 == 0;

	  /* Set seed to be the number of seconds since jan 1, 1970 */
	  seed = time(NULL);

	  now = clock();	/* Record start time for sequence */

	  /* Generate a sequence of numbers and display the number */
	  srand((unsigned int)seed); /* initialize the random sequence */
	  for(i = 1; i <= sequence_length; i++)
	  	printf("%d ", rand() % 10); /* output a random digit */

	  /* Wait one second */
	  for( ;clock() - now < CLOCKS_PER_SEC; );

	  /* Now overwrite the digit sequence */;
	  printf("\r");      /* Go to the beginning of the line */
	  for( i = 1; i <= sequence_length; i++)
	  	printf("  ");   /* output two spaces */

	  if(counter == 1)   /* Only output message for the first try */
	  	printf("\nNow you enter the sequence - don't forget"
										" the spaces\n");
	  else
	  	printf("\r");   /* Back to the beginning of the line */

	  /* Check the input sequence of digits against the original */
	  srand((unsigned int)seed);  /* restart the random sequence */
	  for(i = 1; i <= sequence_length; i++)
	  {
	   scanf("%d", &number);		/* Read an input number */
	   if(number != rand() % 10)  /* Compare against random digit */
	   {
	    correct = FALSE;		/* Incorrect entery */
	    break;				/* no need to check further */
	   }
	  }
	  printf("%s\n", correct ? "Correct!" : "Wrong!");
	 }

	 /* Calculate total time to play the game in seconds */
	 time_taken = (clock() - time_taken) / CLOCKS_PER_SEC;

	 /* Output game score */
	 printf("\n\n Your score is %d", --counter * 100 / time_taken);

	 fflush(stdin);

	 /* Check if new game is required */
	 printf("\nDo you want to play again (y/n)? ");
	 scanf("%c", &another_game);
	}while(toupper(another_game) == 'Y');
	/* system("PAUSE"); <-dos command */
	return 0;
}
