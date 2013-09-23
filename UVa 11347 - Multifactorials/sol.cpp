#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c[1005];
int  f[1005];
int  p[1005];
int  u[1005];

int main()
{
    memset( u, 0, sizeof(u) );
    int count = 0;
    for ( int i = 2 ; i <= 1000 ; ++ i )
        if ( !u[i] )
        {
            p[count++] = i;
            for ( int j = 2 * i ; j <= 1000 ; j += i )
                u[j] = 1;
        }

    int n, m;
    while ( scanf("%d", &m) != EOF )
        for ( int i = 1 ; i <= m ; ++ i )
        {
            scanf("%d%s", &n, c);
            int k = strlen(c);
            memset( f, 0, sizeof(f) );

            while ( n > 0 )
            {
                int v = n, s = 0;
                while ( v > 1 && s < count )
                {
                    while ( v % p[s] == 0 )
                    {
                        v /= p[s];
                        f[s] ++;
                    }
                    s ++;
                }
                n -= k;
            }

            double ans = 1.0;
            for ( int j = 0 ; j < count ; ++ j )
                ans *= (1.0 + f[j]);

            printf("Case %d: ", i);
            if ( ans > 1e18 )
                printf("Infinity\n");
            else printf("%.0lf\n", ans);
        }
    return 0;
}
