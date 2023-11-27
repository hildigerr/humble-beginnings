/* f=9/5*c+32 *///Add -r for "reverse" to c2f/f2c
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
    double f = 32.0, c;

    if( argv[0][0] == 'c' ) {
        if( argc < 2 ) {
            printf("\nWhat is the temperature you whish to convert, in celcious? ");
            scanf("%lf", &c);
        } else c = atof( argv[1] );
        f += ( 1.8 * c );
    } else { /* f2c */
        if( argc < 2 ) {
            printf("\nWhat is the temperature you whish to convert, in fahrenheit? ");
            scanf("%lf", &c);
        } else c = atof( argv[1] );
        f = ((c - f)*(5/9));
    } printf("%.2f\n", f);

    return 0;
}/* End main Func */
