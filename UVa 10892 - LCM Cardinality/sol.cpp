#include <stdio.h>
#include <vector>

using namespace std;

long long gcd(long long a, long long b)
{
    return b == 0LL ? a : gcd( b, a % b );
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int n;

    while ( scanf("%d", &n), n )
    {
        vector<int> d;
        for (int i = 1; i * i <= n; i++)
        {
            if ( n % i == 0 )
            {
                d.push_back( i );
                if ( i != n / i ) d.push_back( n / i );
            }
        }
        int ans = 0;
        for (int i = 0; i < d.size(); i++)
            for (int j = 0; j <= i; j++)
                if ( lcm( d[i], d[j] ) == n )
                    ans++;
        printf("%d %d\n", n, ans);
    }

    return 0;
}