
#include <stdio.h>

void putmonth(int x);

typedef struct {
        float cost;
        float min;
        float max;
        float min_pay;
        float total_paid;
        float mo_payment[12];
                } COMP;

int main()
{
    COMP mycomp,
         hercom,
         totals;
    float apr[2]= {14.99, 29.99}; /* standard interest rate:0-min/1-max */
    int x;

    apr[0] /= 100;
    apr[1] /= 100;

    printf("apr min %f\tapr max %f", apr[0], apr[1]);
    printf("\n\t%f\t%f\n", apr[0]/12, apr[1]/12);

    puts("Hildigerr's program for");
    puts("                calculating the cost of our new computers.");

    printf("\nEnter the cost for Hildigerr's computer: ");
    scanf("%f", &mycomp.cost);
    totals.cost = mycomp.cost;
    printf("What are the montly min payments? ");
    scanf("%f", &mycomp.min_pay);
    totals.min_pay = mycomp.min_pay;
    printf("Enter the cost for Morgan's computer: ");
    scanf("%f", &hercom.cost);
    totals.cost += hercom.cost;
    printf("What are the montly min payments? ");
    scanf("%f", &hercom.min_pay);
    totals.min_pay += hercom.min_pay;

    printf("\nThe subtotal cost is $%.2f.\n", totals.cost);
    mycomp.cost += 19.99;
    hercom.cost += 19.99;
    totals.cost = mycomp.cost + hercom.cost;
    printf("\nThe subtotal cost after shipping is $%.2f.\n", totals.cost);
    printf("The subtotal minimum monthly payment is $%.2f.\n", totals.min_pay);
    /*system("PAUSE");*/

    mycomp.total_paid = 0;
    hercom.total_paid = 0;
    totals.total_paid = 0;

    for(x=0; x<12; x++)
    {
        putmonth(x);
        printf("\nHildiger: THIS MONTHS PAYMENT: $");
        scanf("%f", &mycomp.mo_payment[x]);
        mycomp.total_paid += mycomp.mo_payment[x];
        printf("Morgan: THIS MONTHS PAYMENT: $");
        scanf("%f", &hercom.mo_payment[x]);
        hercom.total_paid += hercom.mo_payment[x];
        totals.mo_payment[x] = mycomp.mo_payment[x] + hercom.mo_payment[x];
        totals.total_paid += totals.mo_payment[x];
    }/*end monthly for*/
    /*system("PAUSE");*/

    apr[0] /= 12;
    apr[1] /= 12;

    mycomp.min = mycomp.cost;
    mycomp.max = mycomp.cost;
    hercom.min = hercom.cost;
    hercom.max = hercom.cost;
    totals.min = totals.cost;
    totals.max = totals.cost;

    printf("\tHILDIGERR\tMORGAN\t\tTOTAL\n");
    printf("\tMIN\tMAX\tMIN\tMAX\tMIN\tMAX\n");

    for(x=0; x<12; x++)
    {
        putmonth(x);

        printf("\t");
        mycomp.min -= mycomp.mo_payment[x];
        mycomp.min += mycomp.min * apr[0];
        printf("$%.2f\t", ((mycomp.min > 0) ? mycomp.min : 0));
        mycomp.max -= mycomp.mo_payment[x];
        mycomp.max += mycomp.max * apr[1];
        printf("$%.2f\t", ((mycomp.max > 0) ? mycomp.max : 0));

        /*printf("\t");*/
        hercom.min -= hercom.mo_payment[x];
        hercom.min += hercom.min * apr[0];
        printf("$%.2f\t", ((hercom.min > 0) ? hercom.min : 0));
        hercom.max -= hercom.mo_payment[x];
        hercom.max += hercom.max * apr[1];
        printf("$%.2f\t", ((hercom.min > 0) ? hercom.min : 0));

        /*printf("\t");*/
        totals.min -= totals.mo_payment[x];
        totals.min += totals.min * apr[0];
        printf("$%.2f\t", ((totals.min > 0) ? totals.min : 0));
        totals.max -= totals.mo_payment[x];
        totals.max += totals.max * apr[1];
        printf("$%.2f\n", ((totals.min > 0) ? totals.min : 0));
    }

    /*system("PAUSE");*/
    return 0;
}
void putmonth(int x)
{
    switch(x)
    {
        case 0:
            printf("APR");
            break;
        case 1:
            printf("MAY");
            break;
        case 2:
            printf("JUN");
            break;
        case 3:
            printf("JUL");
            break;
        case 4:
            printf("AUG");
            break;
        case 5:
            printf("SEP");
            break;
        case 6:
            printf("OCT");
            break;
        case 7:
            printf("NOV");
            break;
        case 8:
            printf("DEC");
            break;
        case 9:
            printf("JAN");
            break;
        case 10:
            printf("FEB");
            break;
        case 11:
            printf("MAR");
            break;
    }/*end x switch*/
}
