/* RMHV 0.2 */

/* TODO: check for same first initial */

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#define MIN_ARG 2 /* How many CLI parameters do we need? */
#define MAX_ARG 6 /* How much is too much? */

#define MAX_PLAY 4 /* Max qt of players *//*CHANGE AFFECTS SWITCH*/
#define MIN_PLAY 2 /* Min qt of players */

#define MAX_LIFE 100 /* Maximum initial life */
#define BAS_LIFE 20 /* Base initial life */
#define MIN_LIFE 0 /* Minimum initial life *//*DONTCHANGE*/

#define VERSION 0.2 /* use -v to check version to make sure is up to date */

void display_help( char* agv0 );

int main( int argc, char *argv[] )
{
	int life[MAX_PLAY];
	int i, gofirst, life_i = BAS_LIFE, pqt = 0, how;
	bool run = true, named_players = true, life_inverse = false;
	char * pname[MAX_PLAY];
	char who, what;

	srand( time( NULL ) );

	if( ( argc < MIN_ARG ) || ( argc > MAX_ARG ) )
	{
		display_help( argv[0] );
		run = false;
	}/* end bad CLI paramaters */

	for( i = 1; i < argc; i++ )
	{
		if( !run ) exit( EXIT_SUCCESS ); /* Just in Case */
		if( argv[i][0] == '-' ) /* SWITCH */
		{
			if( argv[i][1] == '\0' )
			{
				cout << "\nError: Forgot switch option." << endl;
				exit( EXIT_FAILURE );
			}/* end forgot switch opt if */
			else if( ( argv[i][1] == 'H' ) || ( argv[i][1] == 'h' ) )
			{
				display_help( argv[0] );
				exit( EXIT_SUCCESS );
			}/* end help switch */
			else if( ( argv[i][1] == 'L' ) || ( argv[i][1] == 'l') )
			{
				life_i = atoi( argv[i+1] );
				if( ( life_i < MIN_LIFE ) || ( life_i > MAX_LIFE ) )
				{
					cout << "\nError: Initial life out of range: " << life_i << endl;
					exit( EXIT_FAILURE );
				}/* end bad life_i input if */
				if( life_i == MIN_LIFE ) life_inverse = true;
			}/* end life switch */
			else if( ( argv[i][1] == 'P' ) || ( argv[i][1] == 'p') )
			{
				pqt = atoi( argv[i+1] );
				if( ( pqt < MIN_PLAY ) || ( pqt > MAX_PLAY ) )
				{
					cout << "\nError: Player quantity out of range: " << pqt << endl;
					exit( EXIT_FAILURE );
				}/* end bad pqt input if */
				named_players = false;
			}/* end player switch */
			else if( ( argv[i][1] == 'V' ) || ( argv[i][1] == 'v') )
			{
				cout << argv[0] << " v:" << VERSION << endl;
				exit( EXIT_SUCCESS );
			}/*end version check switch option */
			else
			{
				cout << "\n\nUnknown command line option." << endl;
				display_help( argv[0] );
				exit( EXIT_FAILURE );
			}/* end unused CLI option */
		}/* end SWITCH if */
		else if( isalpha( argv[i][0] ) )
		{
			if( ++pqt > MAX_PLAY )
			{
				cout << "\nError: Too many players: " << pqt << endl;
				/* TODO:List players */
				exit( EXIT_FAILURE );
			}/* end too many players if */
			else
				pname[pqt - 1] = argv[i];
		}/* end assume player name if */
	}/* end argc for */

	if( pqt < MIN_PLAY ) run = false;
	if( !run ) exit( EXIT_SUCCESS ); /* Just in Case */
	for( i = 0; i < pqt; i++ ) life[i] = life_i;

	gofirst = rand() % pqt;
	if( named_players ) cout << "\t" << pname[gofirst] << " goes first.\n";
	else cout << "\tPlayer #" << ( gofirst + 1 ) << " is first.\n";

	while( run )
	{
		cout << "PLAYER:\t";
		for( i = 0; i < pqt; i++ )
			if( named_players ) cout << pname[i] << "\t";
			else cout << ( i + 1 ) << "\t";
		cout << endl << "LIFE:\t";
		for( i = 0; i < pqt; i++ ) cout << life[i] << "\t";

		do{
			cout << endl << "-->:";
			cin >> who >> what >> how;
		}while( ( ( what != '+' ) && ( what != '-' ) ) || ( ( how < 0 ) || ( how > MAX_LIFE ) ) );

		/*TODO:Verify input*/

		if( what == '+' )
		{
			if( ( who == '1' ) || ( who == toupper( pname[0][0]) ) || ( who ==  tolower( pname[0][0]) ) )
				life[0] += how;
			else if( ( who == '2' ) || ( who == toupper( pname[1][0]) ) || ( who ==  tolower( pname[1][0]) ) )
				life[1] += how;
			else if( ( who == '3' ) || ( who == toupper( pname[2][0]) ) || ( who ==  tolower( pname[2][0]) ) )
			{
				if( pqt < 3 ) exit( EXIT_FAILURE );/*TODO: err output */
				life[2] += how;
			}/* end 3 who if */
			else if( ( who == '4' ) || ( who == toupper( pname[3][0]) ) || ( who ==  tolower( pname[3][0]) ) )
			{
				if( pqt < 4 ) exit( EXIT_FAILURE );/*TODO: err output */
				life[3] += how;
			}/* end 4 who if */
			else
			{
				cout << "Who?" << endl;
			}/* end who else if */
		}/* end + what if */
		else if( what == '-' )
		{
			if( ( who == '1' ) || ( who == toupper( pname[0][0]) ) || ( who ==  tolower( pname[0][0]) ) )
				life[0] -= how;
			else if( ( who == '2' ) || ( who == toupper( pname[1][0]) ) || ( who ==  tolower( pname[1][0]) ) )
				life[1] -= how;
			else if( ( who == '3' ) || ( who == toupper( pname[2][0]) ) || ( who ==  tolower( pname[2][0]) ) )
			{
				if( pqt < 3 ) exit( EXIT_FAILURE );/*TODO: err output */
				life[2] -= how;
			}/* end 3 who if */
			else if( ( who == '4' ) || ( who == toupper( pname[3][0]) ) || ( who ==  tolower( pname[3][0]) ) )
			{
				if( pqt < 4 ) exit( EXIT_FAILURE );/*TODO: err output */
				life[3] -= how;
			}/* end 4 who if */
			else
			{
				cout << "Who?" << endl;
			}/* end who else if */
		}/* end - what if */
		else
		{
			cout << "What?" << endl;
		}/* end err what if */

		if( life_inverse )
		{
			for( i = 0; i < pqt; i++ ) if( life[i] == -20 ) run = false;
		}/* end life_default if */
		else /* initial life is changed */
		{
			for( i = 0; i < pqt; i++ ) if( life[i] == 0 ) run = false;

		}/* end L switch effect */

		system("clear"); /* WINDOWS use "cls" */
	}/* end run while */
	
	return 0;
}

void display_help( char* agv0 )
{
		cout << "\nUsage:\n\t" << agv0 <<" [-option] [player1_name] [player2_name] [player3_name] [player4_name]\n"
				<< "\noptions:\n-h\tDisplay this Help\n-v\tDisplay version info\n-L #\tStart with # Life, must be between " << MIN_LIFE <<" and " << MAX_LIFE
				<< "\n-P #\tPlay with # players, each refered to by # only.\n" << "\n\nYou may have "<< MIN_PLAY << " to "
				<< MAX_PLAY<< " players, whose life points will start at a default of " << BAS_LIFE
				<< ".\nThe program will randomly decide who should go first, refering to the player by name and/or number.\n" 
				<< "Then it will display a table of the players and their assosiated health points, followed by a prompt.\n"
				<< "At the prompt, simply enter the number, or first initial, of the player followed by ( + or - ) and then the number"
				<< " you wish the health to be adjusted by." << endl;
}
