#include <stdio.h>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int x, y, cases, i;
    long ans;
    scanf("%d", &cases);
    for (i = 1; i < cases + 1; i++)
    {
        scanf("%d %d", &x, &y);
        if (x == y)
            ans = 2;
        else
        {
            int temp = gcd(x, y);
            ans = x / temp + y / temp;
        }
        printf("Case %d: %ld\n", i, ans);
    }
    return 0;
}