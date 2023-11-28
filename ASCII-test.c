
#include <stdio.h>

int main ()
{
	unsigned char ltr;
	int qt;

	printf("TEST HOW MANY? ");
	scanf("%d", &qt);
	for(;qt>0;qt--)
	{
		printf("<0-255>->");
		scanf("%d", &ltr);
		printf("%d = %c\n", ltr, ltr);
	}
	/* system("PAUSE"); <-dos comand */
	return 0;
}
