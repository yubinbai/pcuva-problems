#include <cstdio>
#include <cmath>

void gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long a, b, c, d, k, x, y;
        scanf("%lld%lld", &c, &k);
        a = floor(1.*c / k);
        b = ceil(1.*c / k);
        gcd(a, b, d, x, y);
        x *= c / d;
        y *= c / d;
        printf("%lld %lld\n", x, y);
    }
    return 0;
}