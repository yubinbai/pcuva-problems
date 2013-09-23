#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

char face[6][10] = { "front", "back", "left", "right", "top", "bottom"};


int dp[3001], p[3001], cu[6], top[3001], bot[3001], num[3001], df[3001];
int n, m;
void printpath( int k)
{
    if ( k == -1)
        return ;
    printpath( p[k] );
    printf("%d %s\n", num[k], face[df[k]]);
}
int main()
{
    int t = 1, first = 1;
    while ( scanf("%d", &n) == 1 && n)
    {
        if ( !first)
            printf("\n");
        else
            first = 0;
        m = 0;
        int i, j;
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < 6; j++)
                scanf("%d", &cu[j]);
            for ( j = 0; j < 6; j++)
            {
                df[m] = j;
                num[m] = i + 1;
                top[m] = cu[j];
                if ( j % 2)
                    bot[m] = cu[j - 1];
                else
                    bot[m] = cu[j + 1];
                m++;
            }
        }
        memset( dp, 0, sizeof( dp));
        memset( p, -1, sizeof( p));
        for ( i = 0; i < m; i++)
            for ( j = i + 1; j < m; j++)
                if ( num[j] > num[i] && bot[i] == top[j] && dp[j] < dp[i] + 1)
                {
                    dp[j] = dp[i] + 1;   p[j] = i;
                }
        int max = 0, k = 0;
        for ( i = 1; i < m; i++)
            if ( dp[i] > max)
            {
                max = dp[i];
                k = i;
            }
        printf("Case #%d\n%d\n", t++, max + 1);
        printpath(k );
    }
    return 0;
}