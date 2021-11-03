/* Karol Żuraniewski */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FACTORIAL_TYPE unsigned int

FACTORIAL_TYPE silnia_rek(int a)
{
    if (a < 0)
        return -1;

    return a > 2 ? silnia_rek(a - 1) * a : a;
}

FACTORIAL_TYPE silnia_it(int a)
{
    if (a < 0)
        return -1;

    FACTORIAL_TYPE i = 1;

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

    char *pEnd;
    int inp = strtod(argv[1], &pEnd);

    if (*pEnd != 0 || inp <= 0)
    {
        fprintf(stderr, "argument must be a number greater than 0\n");
        return 1;
    }

    /* --- */

    FACTORIAL_TYPE rek, it;

    rek = silnia_rek(inp);
    it = silnia_it(inp);

    printf("(recursion) n! = %d\n", rek);
    printf("(iteration) n! = %d\n", it);

    return 0;
}