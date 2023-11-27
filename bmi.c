#include<stdio.h>

int main( void )
{
     float bmi, wt, ht;

     printf("\n\tBody-Mass Index\n\nBody mass index (BMI) is a measure of body fat based on height and weight that applies to adult men and women.\n\nWhat is your WT in LBS? ");
     scanf("%f", &wt);
     printf("What is your HT in INCHES? ");
     scanf("%f", &ht);

     bmi = 703*wt/(ht*ht);

     printf("\nBMI = %.1f\n", bmi);

	printf("\nYou are %s.\n\n", (bmi < 18.5)? "underweight": (bmi < 24.9 )? "of normal weight": (bmi < 29.9)? "overweight": "obese");

     return 0;
}
