/* Karol Żuraniewski */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SILNIA_TYP unsigned long long

SILNIA_TYP silnia_rek(int a)
{
    if (a < 0)
        return -1;

    return a > 2 ? silnia_rek(a - 1) * a : a;
}

SILNIA_TYP silnia_it(int a)
{
    if (a < 0)
        return -1;

    SILNIA_TYP i = 1;

    while (a > 0)
        i *= a--;

    return i;
}

int main(int argc, char *argv[])
{
    char *pEnd;
    int inp = (SILNIA_TYP)strtod(argv[1], &pEnd);

    if (inp <= 0)
    {
        printf("a musi byc wieksze od 0\n");
        return 1;
    }

    printf("silnia rekurencyjna dla %d: %lld\n", inp, silnia_rek(inp));
    printf("silnia iteracyjna dla %d: %lld\n", inp, silnia_it(inp));

    return 0;
}