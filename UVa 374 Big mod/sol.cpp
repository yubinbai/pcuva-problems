#include <stdio.h>
long long int bigmod ( long long a, int p, int m );
int main()
{
    long long a;
    int p, m;
    while (scanf("%lld %d %d", &a, &p, &m) == 3)
        printf("%d\n", bigmod(a, p, m));
    return 0;
}
long long int  bigmod ( long long a, int p, int m )
{
    if ( p == 0 )return 1;
    if ( p % 2 )
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else
    {
        long long c = bigmod ( a, p / 2, m );
        return ( (c % m) * (c % m) ) % m;
    }
}