#include <stdio.h>
#include <math.h>
#include <stdlib.h>
static char *primes;
int sumDigits(int n);

void cachePrimes(int n)
{
    int i, j, k;
    primes = (char *) malloc((n + 1) * sizeof(char));
    primes[0] = 1;
    primes[1] = 1;
    primes[2] = 0;
    k = sqrt(n);
    for (i = 0; i <= n; i++)
        primes[i] = 0;
    for (i = 2; i <= k; i++)
        if (primes[i] == 0)
            for (j = i * i; j <= n; j = j + i)
                primes[j] = 1;

}
int nextP(int p)
{
    if (p == 31607)
        return -1;
    p++;
    while (primes[p])
        p++;
    return p;

}
int sumFactors(int n)
{
    int k = n;
    int p = 2;
    int sum = 0;
    if (n <= 31622 && !primes[n])
        return -1;
    while (p != -1 && n != 1)
    {
        int c = 0;
        while (n % p == 0 && n != 1)
        {
            n = n / p;
            c++;
        }
        sum = sum + c * sumDigits(p);
        p = nextP(p);
    }
    if (n == k)
        return -1;
    if (n != 1)
        sum += sumDigits(n);
    return sum;
}
int sumDigits(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n = n / 10;
    }
    return s;
}
int main()
{
    int i, n, k;
    scanf("%d", &i);
    cachePrimes(31622);
    while (i > 0)
    {
        scanf("%d", &n);
        for (k = n + 1;; k++)
        {
            if (sumDigits(k) == sumFactors(k))
            {
                printf("%d\n", k);
                break;
            }
        }
        i--;
    }
    return 0;
}