/* Karol Żuraniewski */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	int inp;

	while (scanf(" %d", &inp) != 1)
	{
		printf("niepoprawne dane\n");

		do
			inp = getchar();
		while (inp != '\n');
	}

	return 0;
}