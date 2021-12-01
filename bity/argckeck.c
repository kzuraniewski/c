#define argcheck(ARGS)                                          \
    if (argc < ARGS + 1 || *argv == 0)                          \
    {                                                           \
        fprintf(stderr, "no argument specified\n");             \
        return 1;                                               \
    }                                                           \
    if (ARGS > 1)                                               \
    {                                                           \
        char *pEnd;                                             \
        double inp[ARGS];                                       \
        int i = ARGS;                                           \
        while (i--)                                             \
        {                                                       \
            inp[i] = strtod(argv[i + 1], &pEnd);                \
            if (*pEnd != 0 || inp <= 0)                         \
            {                                                   \
                fprintf(stderr, "argument must be a number\n"); \
                return 1;                                       \
            }                                                   \
        }                                                       \
    }
