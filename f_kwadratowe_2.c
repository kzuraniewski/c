/* Karol Żuraniewski */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define a in[0]
#define b in[1]
#define c in[2]

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		printf("Bledna ilosc argumentow\n");
		return 1;
	}

	double in[3], delta;
	char *pEnd;

	int i = 0;
	while (i < 3)
	{
		in[i] = strtod(argv[i + 1], &pEnd);

		/* if (*pEnd != '\n')... */

		if (pEnd != argv[i + 1] + strlen(argv[i + 1]))
		{
			printf("nieprawidlowe dane\n");
			return 1;
		}

		if (i == 0 && in[0] == 0)
		{
			printf("a nie moze byc 0\n");
			return 1;
		}

		i++;
	}

	delta = b * b - 4 * a * c;

	if (delta > 0)
		printf(
			"Dwa pierwiastki rzeczywiste: %f, %f\n",
			(-b - sqrt(delta)) / (2 * a),
			(-b + sqrt(delta)) / (2 * a));
	else if (delta == 0)
		printf(
			"Jeden pierwiastek rzeczywisty: %f\n",
			-b / (2 * a));
	else
		printf("Brak pierwiastków rzeczywistych: (+-i)\n");

	return 0;
}
