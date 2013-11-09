#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    double n, x, f, digit, a;
    while (scanf("%lf", &n) == 1)
    {
        digit = floor(log10(2) * n + 1);
        printf("2^-%.0lf = %.3lfe%.0lf\n", n,
               pow(2.0, (digit / log10(2.0) - n)), -digit);
    }
    return 0;
}