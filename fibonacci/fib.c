/* Karol Żuraniewski */

/**
 * iteracja szybsza 
 * max: 46
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ITERATIONS 1
#define FIB_TYPE double

FIB_TYPE fib_it(int a)
{
    int prev = 1, curr = 1, i, t;

    for (i = 2; i < a; i++)
    {
        t = curr;
        curr += prev;
        prev = t;
    }

    return curr;
}

FIB_TYPE fib(int a)
{
    if (a <= 0)
        return -1;

    if (a <= 2)
        return 1;

    return fib(a - 1) + fib(a - 2);
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

    /*---*/

    FIB_TYPE out;
    int i = ITERATIONS;

    while (i--)
        out = fib_it(inp);

    printf("%f\n", out);

    return 0;
}