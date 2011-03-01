
#include <stdio.h>

#define TOP 1
#define BTM 0

int board_top[8] = {0, 4, 4, 4, 4, 4, 4, 0},
    board_btm[8] = {0, 4, 4, 4, 4, 4, 4, 0};
int select = 0,
    sec = 2,
    top_btm;
int *ptr;

void movebuttons(int trn);
void test_opp(int trn);
void print_board(void);
void pause(int inNum);
void sys_pause(void);

int main(void)
{
     int turn;
	int t, done_top, done_btm;
	char yn;
	srand(time(NULL));

	system("clear");
	printf("\t*==================*\n");
	printf("\t| The Buttons Game |\n");
	printf("\t|    or MANCALA    |\n");
	printf("\t|   by Hildigerr   |\n");
	printf("\t*==================*\n");
	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
	system("clear");

	puts("Mancala is one of the oldest two-player strategy games in ");
	puts("the world, with many variations. I call it the buttons game");
	puts("because my wife and I use to play it with buttons on a board");
	puts("drawn on a pice of cardboard.");
	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();

	puts("The goal of the game is to capture as many \"buttons\" or");
	puts("playing pieces as possible.");
	puts("\nThe game begins with 4 buttons in each section except in the");
	puts("troughs on each side, which are used to keep score.");
	puts("\nThe first player to move is randomly chosen.");
	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();

	puts("The player gathers all the pieces in one of their trays, which you");
	puts("select by entering the coresponding numbers 1 through 6, and");
	puts("sows the pieces, one-by-one in each pit, around the board");
	printf("clockwise, skipping over their opponent's trough, which is on the");
	printf(" left.\n\nIf a player's last piece lands in their own Kalaha,\n");
	puts("then the player gets another turn.-not implemented");
	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
	system("clear");
	puts("A player may capture the pieces in their opponent's");
	puts("pit if their last piece is sown in an empty pit on");
	puts("their own side of the board. The player then gets to");
	puts("capture all of the pieces from both sides and store");
	puts("them in their own trough.");
	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();

	puts("When all six pits on one side of the board are empty,");
	puts("the game is over. The player who still has playing");
	puts("pieces in their own pits gets to put them in thier");
	puts("own Kalaha(trough). The winner is the player with");
	puts("the most \"buttons\" or pieces in their own Kalaha.");
	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
	system("clear");
	printf("Do you still want to play? ( Y or N ) :");
	scanf("%c", &yn);
	do{
	printf("Select game speed: ");
	printf("(0=auto, 1=fast, 2=suggested, 3=slow, 4=tedious) ");
	scanf("%d", &sec);
	}while(sec<0||sec>4);

	turn = rand() % 10 +1;	/* randomly start 1st or 2nd */

	print_board();

	while(yn == 'y' || yn == 'Y')
	{
		done_top = 0; done_btm = 0;	/*reset*/
		for(t=1; t < 7; t++)
		{
			done_top += board_top[t];
			done_btm += board_btm[t];
		}
		if(done_top != 0 && done_btm != 0)
		{
			switch(turn %2)
			{
			 case 0:
			 {
			  top_btm = BTM;
			  do{
			   fflush(stdin);
			   printf("It's your turn: ");
			   scanf("%d", &select);
			   ptr = &board_btm[select];
			  }while (select < 1 || select > 6 || board_btm[select] < 1);
			  movebuttons(turn % 2);
			  break;
			 }/*end player turn case*/
			 case 1:
			 {
			  top_btm = TOP;
			  puts("It's my turn.");
			  do{
			   select = rand() % 6 +1;
			   ptr = &board_top[select];
			  }while (board_top[select] < 1);
			  /* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
			  movebuttons(turn %2);
			  break;
			 }/*end computer turn case*/
			 default: { puts("error 68"); }
			}/*end turn switch*/
			turn++;
		}else yn = 'G';
	}/*end yn while*/

	/*GameOver*/
	for(t = 1; t < 7; t++)
	{					/*tally pts*/
	 board_btm[7] += board_btm[t];
	 board_btm[t] = 0;
	 board_top[0] += board_top[t];
	 board_top[t] = 0;
	}
	print_board();
	if( board_btm[7] > board_top[0] ) puts("YOU WIN!");
	if( board_btm[7] < board_top[0] ) puts("YOU LOOSE!");
	if( board_btm[7] == board_top[0]) puts("Bye-Bye!");

	/* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
	return 0;
}/*end main*/
void sys_pause(void)
{
	puts("Press Enter to continue...");
	/*fflush(stdin);*/
	getchar();
	/*fflush(stdin);*/
}
void print_board(void)
{
	int board_width[8];
	int x;

	board_btm[7] += board_top[7];	/*my pts*/
	board_top[7] = 0;
	board_top[0] += board_btm[0];	/*comp pts*/
	board_btm[0] = 0;

	/*set board_witdth*/
	for(x = 0; x < 8; x++)
	{
		if(board_top[x] > 9) board_width[x] = 2;
		else board_width[x] = 1;
	}
	for(x = 0; x < 8; x++)
	{
		if(board_btm[x] > 9) board_width[x] = 2;
	}

	system("clear");
	for(x=1; x < 8; x++) printf("\n");

	/*Top Boarder*/
	if( board_width[0] == 2) printf("*==");
		else printf("*=");
	for(x = 1; x < 7; x++)
	{
		if( board_width[x]== 2 ) printf("===");
			else printf("==");
	}
	if( board_width[7] == 2 ) printf("===*\n");
		else printf("==*\n");

	/*Top Trays*/
	for(x = 0; x < 7; x++)
	{
		if( board_top[x] > 9 ) printf("|%d", board_top[x]);
			else if( board_width[x] == 2 ) printf("| %d", board_top[x]);
				else printf("|%d", board_top[x]);
	}
	if( board_width[7] == 2 ) printf("|  |\n");
		else printf("| |\n");

	/*Mid Boarder*/
	if( board_width[0] == 2 ) printf("|  |");
		else printf("| |");
	for(x = 1; x < 6; x++)
	{
		if( board_width[x]== 2 ) printf("==+");
			else printf("=+");
	}
	if( board_width[6] == 2 ) printf("==|");
		else printf("=|");
	if( board_width[7] == 2 ) printf("  |\n");
		else printf(" |\n");

	/*Btm Trays*/
	if( board_width[0] == 2 ) printf("|  ");
		else printf("| ");
	for(x = 1; x <= 7; x++)
	{
		if( board_btm[x] > 9 ) printf("|%d", board_btm[x]);
			else if( board_width[x] == 2 ) printf("| %d", board_btm[x]);
				else printf("|%d", board_btm[x]);
	}printf("|\n");

	/*Btm Boarder*/
	if( board_width[0] == 2 ) printf("*==");
		else printf("*=");
	for(x = 1; x < 7; x++)
	{
		if( board_width[x]== 2 ) printf("===");
			else printf("==");
	}
	if( board_width[7] == 2 ) printf("===*\n");
		else printf("==*\n");

	/*tray numbers*/	/*printf("   1 2 3 4 5 6\n");*/
	if( board_width[0] == 2 ) printf("    ");
		else printf("   ");
	if( board_width[1] == 2 ) printf("1  ");
		else printf("1 ");
	if( board_width[2] == 2 ) printf("2  ");
		else printf("2 ");
	if( board_width[3] == 2 ) printf("3  ");
		else printf("3 ");
	if( board_width[4] == 2 ) printf("4  ");
		else printf("4 ");
	if( board_width[5] == 2 ) printf("5  ");
		else printf("5 ");
	if( board_width[6] == 2 ) printf("6  \n");
		else printf("6 \n");
}
void movebuttons(int trn)
{
	int qt = *ptr;
	int pt = qt;
	*ptr = 0;

	while(qt > 0)
	{
	 if (trn == 0)/*my turn*/
	 {
		if (ptr == &board_btm[1]) { top_btm = TOP; ptr = &board_top[0]; }
		if (ptr == &board_top[7]) { top_btm = BTM; ptr = &board_btm[7]; }
		if (top_btm == TOP && ptr < &board_top[7]) { ptr++; *ptr += 1; qt--; }
		if (top_btm == BTM && ptr > &board_btm[1]) { ptr--; *ptr += 1; qt--; }
	 }
	 if (trn == 1)
	 {
		if (ptr == &board_top[6]) { top_btm = BTM; ptr = &board_btm[7]; }
		if (ptr == &board_btm[0]) { top_btm = TOP; ptr = &board_top[0]; }
		if (top_btm == BTM && ptr > &board_btm[0]) { ptr--; *ptr += 1; qt--; }
		if (top_btm == TOP && ptr < &board_top[6]) { ptr++; *ptr += 1; qt--; }
	 }
	 print_board();
	 printf("%d buttons in hand from tray %d\n", qt, select);
	 if(qt != 0 && pt != 1) pause(sec);
	}/*end select while*/
	test_opp(trn);
}
void test_opp(int trn)
{
	int x;

	if(*ptr == 1)
	{
	 switch(top_btm)
	 {
	  case 0: /*BTM*/
	  {
	   if( trn == 0)/* my turn */
	   {
	    for(x = 1; x < 7; x++)
	    {
		if( &board_btm[x] == ptr && board_top[x] > 0)
		{
		 printf("You get %d buttons from the #%d trays!\n", board_top[x]+1, x);
		 /* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
		 board_btm[7] += (board_top[x] + 1);
		 board_btm[x]--;
		 board_top[x] = 0;
		 print_board();
		}
	    }/*end for*/
	   }/*end my turn if*/
	   break;
	  }/*end btm case*/
	  case 1: /*TOP*/
	  {
	   if( trn == 1 )
	   {
	    for(x = 1; x < 7; x++)
	    {
		if( &board_top[x] == ptr && board_btm[x] > 0)
		{
		 printf("I get %d buttons form the #%d trays!\n", board_btm[x]+1, x);
		 /* system("PAUSE");<-dos command | for linux ->*/ sys_pause();
		 board_top[0] += (board_btm[x] + 1);
		 board_top[x]--;
		 board_btm[x] = 0;
		 print_board();
		}
	    }/*end for*/
	   }/*end comp turn*/
	   break;
	  }/*end top case*/
	 }/*end all cases*/
	}/*end last_tray if*/
}
void pause(int inNum)
{
	int iCurrentTime = 0;
	int iElapsedTime = 0;

	iCurrentTime = time(NULL);

	do{
		iElapsedTime = time(NULL);
	}while( (iElapsedTime-iCurrentTime)<inNum );

}
