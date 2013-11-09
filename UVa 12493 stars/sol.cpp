#include <stdio.h>
#include <math.h>
int euler(int n)
{
    int ret = 1, i;
    for (i = 2; i <= sqrt(n) + 1; i++)
        if (n % i == 0)
        {
            n = n / i;
            ret *= (i - 1);
            while (n % i == 0)
            {
                n /= i;
                ret *= i;
            }
        }
    if (n > 1)
        ret *= (n - 1);
    return ret;
}
int main()
{
    int t, a, j;
    while (scanf("%d", &a) != EOF)
    {
        printf("%d\n", euler(a) / 2);
    }
    return 0;
}