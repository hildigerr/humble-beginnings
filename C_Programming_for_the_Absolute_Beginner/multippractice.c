
#include <stdio.h>

int main ()
{
	int x, iNumQuestions, iResponse, iRndNum1, iRndNum2, r =0, w =0;
	float percent =100;
	srand(time(NULL));

	printf("\nEnter number of questions to ask: ");
	scanf("%d", &iNumQuestions);

	for ( x = 0; x < iNumQuestions; x++)
	{
	 iRndNum1 = rand() % 12 + 1;
	 iRndNum2 = rand() % 12 + 1;

	 printf("\nWhat is %d x %d: ", iRndNum1, iRndNum2);
	 scanf("%d", &iResponse);

	 if ( iResponse == iRndNum1 * iRndNum2 )
	 {
	  printf("\nCORRECT!\n");
	  r++;
	 }/*end correct response if*/
	 else
	 {
	  printf("\nThe correct answer was %d \n", iRndNum1 * iRndNum2);
	  w++;
	 }/*end wrong else*/
	}/*end iNumQuestions for*/
	printf("You got %d right and %d wrong.\n", r, w);
	/* percent *= (r / iNumQuestions);*/ /*  <-------------why not work?*/
	/* printf("That is %f percent.\n", percent); */
	/* system("PAUSE"); <---dos command */
	return 0;
}/*end main*/
