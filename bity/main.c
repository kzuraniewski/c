#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "print_bit.h"

#define ARG *argv[1]

int main(int argc, char *argv[])
{
    if (argc < 2 || *argv == 0)
    {
        fprintf(stderr, "no argument specified\n");
        return 1;
    }

    /* --- */

    printf("%d\n", print_bit(ARG, 0));

    return 1;
}