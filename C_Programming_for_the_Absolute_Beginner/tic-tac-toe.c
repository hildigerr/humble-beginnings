/*adjusted by ch6challenge5*/
#include <stdio.h>

void displayBoard(void);
int verifySelection(int, int);
void checkForWin(void);
void clr_scrn(void);

char board[9];
char cWhoWon = ' ';
int iCurrentPlayer = 0;

int main(void)
{
    int x,
        iSquareNum = 0;

    srand(time(NULL));

    for ( x=0; x<9; x++ ) board[x] = ' ';

    displayBoard();

    while ( cWhoWon == ' ')
    {
     printf("\n%c\n", cWhoWon);

     if ( iCurrentPlayer == 1 || iCurrentPlayer == 0 )
     {
        puts("\nPLAYER X");
        printf("Enter an available square number (1-9): ");
        do{
            scanf("%d", &iSquareNum);
        }while(iSquareNum<1||iSquareNum>9);

        if ( verifySelection(iSquareNum, iCurrentPlayer)==1 ) iCurrentPlayer =1;
        else iCurrentPlayer =2;
     }
     else
     {
        puts("PLAYER O");
        printf("Enter an available square number (1-9): ");
        iSquareNum = rand() % 9 +1;

        if ( verifySelection(iSquareNum, iCurrentPlayer)==1 ) iCurrentPlayer =2;
        else iCurrentPlayer =1;
     }
     displayBoard();
     checkForWin();
    }/*end loop*/
    /*system("PAUSE");*/
    return 0;
}
void displayBoard()
{
    clr_scrn();
    printf("\n %c| %c| %c\n", board[0], board[1], board[2]);
    printf("--|--|--\n");
    printf(" %c| %c| %c\n", board[3], board[4], board[5]);
    printf("--|--|--\n");
    printf(" %c| %c| %c\n", board[6], board[7], board[8]);
}
int verifySelection(int iSquare, int iPlayer)
{
 if ( board[iSquare-1]==' ' && (iPlayer ==1 || iPlayer ==0) )
 {
    board[iSquare-1]='X';
    return 0;
 }
 else if ( board[iSquare-1]==' ' && iPlayer == 2 )
 {
    board[iSquare-1]='O';
    return 0;
 }
 else return 1;
}
void checkForWin()
{
    int catTotal;
    int x;

    if      (board[0]=='X' && board[1]=='X' && board[2]=='X') cWhoWon = 'X';
    else if (board[3]=='X' && board[4]=='X' && board[5]=='X') cWhoWon = 'X';
    else if (board[6]=='X' && board[7]=='X' && board[8]=='X') cWhoWon = 'X';
    else if (board[0]=='X' && board[3]=='X' && board[6]=='X') cWhoWon = 'X';
    else if (board[1]=='X' && board[4]=='X' && board[7]=='X') cWhoWon = 'X';
    else if (board[2]=='X' && board[5]=='X' && board[8]=='X') cWhoWon = 'X';
    else if (board[0]=='X' && board[4]=='X' && board[8]=='X') cWhoWon = 'X';
    else if (board[6]=='X' && board[4]=='X' && board[2]=='X') cWhoWon = 'X';
    else if (board[0]=='O' && board[1]=='O' && board[2]=='O') cWhoWon = 'O';
    else if (board[3]=='O' && board[4]=='O' && board[5]=='X') cWhoWon = 'O';
    else if (board[6]=='O' && board[7]=='O' && board[8]=='X') cWhoWon = 'O';
    else if (board[0]=='O' && board[3]=='O' && board[6]=='X') cWhoWon = 'O';
    else if (board[1]=='O' && board[4]=='O' && board[7]=='X') cWhoWon = 'O';
    else if (board[2]=='O' && board[5]=='O' && board[8]=='X') cWhoWon = 'O';
    else if (board[0]=='O' && board[4]=='O' && board[8]=='X') cWhoWon = 'O';
    else if (board[6]=='O' && board[4]=='O' && board[2]=='X') cWhoWon = 'O';

    if (cWhoWon == 'X') { puts("\nX WINS!"); return; }
    if (cWhoWon == 'O') { puts("\nO WINS!"); return; }

    /*check for cat game*/
    for (x=0; x<9; x++) { if (board[x] != ' ') catTotal +=1; }

    if (catTotal==9) {cWhoWon = 'C'; puts("\nCAT GAME!"); return; }
}
void clr_scrn(void)
{
    int x;
    for (x =0;x < 25; x++) printf("\n");
}
