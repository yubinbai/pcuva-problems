#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 1003
#define MAXW 33

int N;
int p[ MAXN ], w[ MAXN ];
int G, MW;
int dp[ MAXN ][ MAXW ];

int main()
{
    int T;

    scanf("%d", &T);
    while ( T-- )
    {
        // Read test case
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d %d", p + i, w + i);

        // Knapsack
        for (int i = 1; i <= N; i++) // for each product
        {
            for (int j = 0; j < MAXW; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if ( w[i] <= j )
                    dp[i][j] = max( dp[i][j], p[i] + dp[i - 1][j - w[i]] );
            }
        }

        scanf("%d", &G);
        int ans = 0;
        for (int i = 0; i < G; i++)
        {
            scanf("%d", &MW);
            ans += dp[ N ][ MW ];
        }
        printf("%d\n", ans);
    }

    return 0;
}
