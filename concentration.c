/*Concentration game from ch4 of c programing for the absolute beginner*/
#include <stdio.h>
#include <stdlib.h>

	char	cYesNo = '\0';
	int	iResp1 = 0;
	int	iResp2 = 0;
	int	iResp3 = 0;
	int	iResp4 = 0;
	int iElapsedTime = 0;
	int iCurrentTime = 0;
	int iRandomNum   = 0;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int iCounter = 0;
	int x;
	int menu = 0;
	int good[3] = { 0, 0, 0 };
	int bad[3]  = { 0, 0, 0 };

void easy(void);
void intermediate(void);
void difficult(void);

int main()
{

	srand(time(NULL));
	system("clear");
	puts("The Concentration Game generates random numbers and displays them");
	puts("for a short period of time for the user to memorize. During the");
	puts("time the random numbers are displayed, the player tries to memorize");
	puts("the numbers and their sequence. After a few seconds have passed,");
	puts("the computer's screen is cleared and the user is asked to input the");
	puts("same numbers in the same sequence.");

	printf("\nPlay a game of Concentration? (y or n): ");
	scanf("%c", &cYesNo);

	if (cYesNo == 'y' || cYesNo == 'Y')
	{
	 while( menu != 4 )
	 {

	  while( menu < 1 || menu > 4 )
	  {
	   puts("\nMenu");
	   printf("1 - EASY\n2 - INTERMEDIATE\n3 - DIFFICULT\n4 - QUIT\n#");
	   scanf("%d", &menu);
	  }

	  switch(menu)
	  {
		case 1:
		{
			easy();
			break;
		}
		case 2:
		{
			intermediate();
			break;
		}
		case 3:
		{
			difficult();
			break;
		}
		default:
		{
			puts("\nSCORES:\t\tright\twrong");
			printf("easy\t\t%d\t%d\n", good[0], bad[0]);
			printf("intermediate\t%d\t%d\n", good[1], bad[1]);
			printf("difficult\t%d\t%d\n", good[1], bad[1]);
			printf("\ntotals\t\t%d\t%d\n", (good[0]+good[1]+good[2]),
						(bad[0]+bad[1]+bad[2]));
		}
	  }
	 }
	}
	printf("\n\nBye-Bye!\n\n");
	return 0;
}
void easy( void )
{
	i1 = rand() % 100;
	i2 = rand() % 100;
	i3 = rand() % 100;

	printf("\nConcentrate on the next three numbers\n");
	printf("\n%d\t%d\t%d\n", i1, i2, i3);

	iCurrentTime = time(NULL);

	do
	{
	 iElapsedTime = time(NULL);
	}while ( (iElapsedTime - iCurrentTime) <3 ); /*end do while loop*/

	for ( x=0; x < 25; x++)
		printf("\n");
	system("clear"); /*the above for doesnt completly clear screen*/

	printf("\nEnter each # separated with one space: ");
	scanf("%d%d%d", &iResp1, &iResp2, &iResp3);

	if ( i1 == iResp1 && i2 == iResp2 && i3 == iResp3 )
	{
		good[0] += 1;
		printf("\nCongratulations!\n");
	}
	else
	{
		bad[0] += 1;
		printf("\nSorry, correct numbers were %d %d %d\n", i1, i2, i3);
	}
}
void intermediate( void )
{
	i1 = rand() % 100;
	i2 = rand() % 100;
	i3 = rand() % 100;
	i4 = rand() % 100;

	printf("\nConcentrate on the next three numbers\n");
	printf("\n%d\t%d\t%d\t%d\n", i1, i2, i3, i4);

	iCurrentTime = time(NULL);

	do
	{
	 iElapsedTime = time(NULL);
	}while ( (iElapsedTime - iCurrentTime) <3 ); /*end do while loop*/

	for ( x=0; x < 25; x++)
		printf("\n");
	system("clear"); /*the above for doesnt completly clear screen*/

	printf("\nEnter each # separated with one space: ");
	scanf("%d%d%d%d", &iResp1, &iResp2, &iResp3, &iResp4);

	if ( i1 == iResp1 && i2 == iResp2 && i3 == iResp3 && i4 == iResp4 )
	{
		good[1] += 1;
		printf("\nCongratulations!\n");
	}
	else
	{
		bad[1] += 1;
		printf("\nSorry, correct numbers were %d %d %d %d\n", i1, i2, i3, i4);
	}
}
void difficult( void )
{
	i1 = rand() % 100;
	i2 = rand() % 100;
	i3 = rand() % 100;
	i4 = rand() % 100;

	printf("\nConcentrate on the next three numbers\n");
	printf("\n%d\t%d\t%d\t%d\n", i1, i2, i3, i4);

	iCurrentTime = time(NULL);

	do
	{
	 iElapsedTime = time(NULL);
	}while ( (iElapsedTime - iCurrentTime) <2 ); /*end do while loop*/

	for ( x=0; x < 25; x++)
		printf("\n");
	system("clear"); /*the above for doesnt completly clear screen*/

	printf("\nEnter each # separated with one space: ");
	scanf("%d%d%d%d", &iResp1, &iResp2, &iResp3, &iResp4);

	if ( i1 == iResp1 && i2 == iResp2 && i3 == iResp3 && i4 == iResp4 )
	{
		good[1] += 1;
		printf("\nCongratulations!\n");
	}
	else
	{
		bad[1] += 1;
		printf("\nSorry, correct numbers were %d %d %d %d\n", i1, i2, i3, i4);
	}
}
