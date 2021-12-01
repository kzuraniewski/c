/* Karol Żuraniewski */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mzero.h"

#define ARGS 4
#define X1 inp[0]
#define X2 inp[1]
#define EPSILON inp[2]
#define METHOD inp[3]

int main(int argc, char *argv[])
{
    if (argc < ARGS + 1 || *argv == 0)
    {
        fprintf(stderr, "no argument specified\n");
        return 1;
    }

    char *pEnd;
    double inp[4];
    int i = ARGS;

    while (i--)
    {
        inp[i] = strtod(argv[i + 1], &pEnd);

        if (*pEnd != 0 || inp <= 0)
        {
            fprintf(stderr, "argument must be a number greater than 0\n");
            return 1;
        }
    }

    /* --- */

    double r;
    int status;

    status = mzero(X1, X2, EPSILON, METHOD, &r);

    if (status < 0)
    {
        printf("brak miejsc zerowych w danym przedziale\n");
        return 1;
    }

    printf("%f\n", r);

    return 0;
}