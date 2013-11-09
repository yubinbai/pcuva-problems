#include <stdio.h>

int main()
{
    long long n;
    while (scanf("%lld", &n) == 1)
    {
        printf("%lld\n", (n / 2 + 2) * (n / 2 + 1) / 2);
    }
    return 0;
}