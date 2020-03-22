
#include <stdio.h>

void cake(float cups);
void activedry(float cups);
void quickrise(float cups);

int main()
{
    int yeast;
    float flour;

    printf("\n\nHILDIGERR'S BREAD MAKING YEAST HELPER\n\n");
    printf("This wil tell you how much yeast to use for however much\n");
    printf("flour you plan to use.");

    printf("\n\nFirst what kind of yeast do you have?\n");
    printf("1-Cake Yeast\n");
    printf("2-Active Dry\n");
    printf("3-Quick Rise\n\n->");
    scanf("%d", &yeast);

    printf("\n\n Now how much flour will you use (in cups)? ");
    scanf("%f", &flour);

    /*How much flour*/

    switch(yeast)
    {
        default:
            printf("\nI've never heard of that kind of yeast.\a");
            break;
        case 1:
            cake(flour);
            break;
        case 2:
            activedry(flour);
            break;
        case 3:
            quickrise(flour);
            break;
    }

    /*system("PAUSE");*/
    return 0;
}

void cake(float cups)
{
    float yeast=.166666;
    yeast *= cups;
    printf("\n\nUse %.2f oz of cake yeast for %.2f cups of flour.\n\n", yeast, cups);
    /* Use 1 oz of cake yeast for 6 cups of flour. */
}

void activedry(float cups)
{
    float yeast=.0625;
    yeast *= cups;
    printf("\n\nUse %.2f oz of active dry yeast for %.2f cups of flour.\n\n", yeast, cups);
    /* Use 3/4 oz of acive dry yeast for 12 cup flour. */
}

void quickrise(float cups)
{
    float yeast = .5;
    yeast *= cups;
    printf("\n\nUse %.2f tsp of quick rise yeast for %.2f cups flour.\n\n", yeast, cups);
    /* Use .5 tsp of quick rise yeast for 1 cup flour. */
}
