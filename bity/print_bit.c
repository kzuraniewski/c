int print_bit(char c, int n)
{
    int mask = 1 << n;

    return (c & mask) >> n;
}