/* f=9/5*c+32 */
#include <stdio.h>

int main(void)
{
    float f=32, c;

    printf("\nWhat is the temperature you whish to convert, in celcious? ");
    scanf("%f", &c);
    f += (1.8*c);
    printf("%.2f\n", f);

    return 0;
}
