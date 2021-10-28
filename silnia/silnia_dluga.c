/* Karol Żuraniewski */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STRONG_TYPE unsigned long long
#define ITERATIONS 1000000000

STRONG_TYPE silnia_rek(int a)
{
    if (a < 0)
        return -1;

    return a > 2 ? silnia_rek(a - 1) * a : a;
}

STRONG_TYPE silnia_it(int a)
{
    if (a < 0)
        return -1;

    STRONG_TYPE i = 1;

    while (a > 0)
        i *= a--;

    return i;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || *argv == 0)
    {
        fprintf(stderr, "no argument specified\n");
        return 1;
    }

    int inp;

    {
        char *pEnd;
        inp = strtod(argv[1], &pEnd);

        if (*pEnd != 0 || inp <= 0)
        {
            fprintf(stderr, "argument must be a number greater than 0\n");
            return 1;
        }
    }

    /* --- */

    {
        STRONG_TYPE rek, it;
        int i;

        for (i = 0; i < ITERATIONS; i++)
            rek = silnia_rek(inp);

        printf("(recursion) n! = %lld\n", rek);

        for (i = 0; i < ITERATIONS; i++)
            it = silnia_it(inp);

        printf("(iteration) n! = %lld\n", it);
    }

    return 0;
}