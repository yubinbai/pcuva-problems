#include <stdio.h>
int fib[39];
int main()
{
    int i, lo, hi, n, mid, start, j, m, c;
    char res[41];
    fib[0] = 1;
    fib[1] = 2;
    for (i = 2; i < 39; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        m = n;
        lo = 0;
        hi = 38;
        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;
            if (fib[mid] < n)
                lo = mid;
            else
                hi = mid;
        }
        if (fib[hi] <= n)
            start = hi;
        else
            start = lo;
        j = 0;
        for (i = start; i >= 0; i--)
            if (n >= fib[i])
            {
                res[j++] = '1';
                n -= fib[i];
            }
            else
                res[j++] = '0';
        res[j] = 0;
        printf("%d = %s (fib)\n", m, res);
    }
    return 0;
}
