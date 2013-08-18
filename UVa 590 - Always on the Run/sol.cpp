#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int day[15][15];
int price[15][15][35];
int dp[15][1005];

int main()
{
    int n, k;
    int cases = 0;
    while (scanf("%d %d", &n, &k) && n && k)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j)
                {
                    scanf("%d", &day[i][j]);
                    for (int d = 1; d <= day[i][j]; ++d)
                        scanf("%d", &price[i][j][d]);
                }

        for (int i = 0; i <= n; ++i)
        {
            for (int d = 0; d <= k; ++d)
                dp[i][d] = INT_MAX;
        }
        dp[1][0] = 0;

        for (int d = 1; d <= k; ++d)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (i != j)
                    {
                        int q = (d - 1) % day[j][i] + 1;
                        if (price[j][i][q] && dp[j][d - 1] != INT_MAX)
                            dp[i][d] = min(dp[i][d], dp[j][d - 1] + price[j][i][q]);
                    }

        printf("Scenario #%d\n", ++cases);
        if (dp[n][k] != INT_MAX)
            printf("The best flight costs %d.\n\n", dp[n][k]);
        else
            printf("No flight possible.\n\n");
    }
    return 0;
}