#include <stdio.h>
int main()
{
    int i, j, k, l, t, f;
    int res;
    while (scanf("%d %d", &i, &j) == 2)
    {
        res = 1, t = 0, f = 0;
        for (k = i; k > i - j; k--)
        {
            l = k;
            while (!(l & 1))
            {
                l >>= 1;
                t++;
            }
            while (l % 5 == 0)
            {
                l /= 5;
                f++;
            }
            res = (res * l) % 10;
        }
        for (i = t; i < f; i++)
            res = (res * 5) % 10;
        for (i = f; i < t; i++)
            res = (res * 2) % 10;
        printf("%d\n", res % 10);
    }
    return 0;
}