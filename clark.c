/* Clark's Rule C=a*w/150 */
#include <stdio.h>

int main (void)
{
    float a, c, w;

   printf("\tChild Dosage Calculator\n\tUsing Clark's Rule\n");
    printf("\nHow much does your child weigh (lbs)? ");
    scanf("%f", &w);
    printf("What is the adult dosage (units irrelevant)? ");
    scanf("%f", &a);

    w /= 150;
    c = a*w;

    printf("The dosage should be %.2f\n", c);
   printf("\nWARNING: Consult your doctor before administering any medication to your child.\n");
    return 0;
}
