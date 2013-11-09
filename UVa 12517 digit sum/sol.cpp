#include <stdio.h>

long sumofDigit(long n, long p10, long pos)
{
    if (n == 0)
    {
        return 0;
    }
    long m = n % 10;
    return n / 10 * 45 * p10 + m * pos + m * (m - 1) / 2 * p10 +
           sumofDigit(n / 10, p10 * 10, pos + m * p10);
}
int main()
{
    long x, y;
    while (1)
    {
        scanf("%ld %ld", &x, &y);
        if (x == 0 && y == 0)
            break;
        printf("%ld\n", sumofDigit(y, 1, 1) - sumofDigit(x - 1, 1, 1));
    }
    return 0;
}