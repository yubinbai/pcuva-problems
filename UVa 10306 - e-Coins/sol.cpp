#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#define min(a,b) (((a) < (b)) ? (a) : (b))

const int MAXN = 301;
int dp[MAXN][MAXN];
int w1[50], w2[50];

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int m, S;
        scanf("%d %d", &m, &S);

        for (int i = 0; i < m; ++i)
            scanf("%d %d", &w1[i], &w2[i]);

        for (int i = 0; i <= S; ++i)
            for (int j = 0; j <= S; ++j)
                dp[i][j] = INT_MAX;
        dp[0][0] = 0;

        for (int i = 0; i < m; ++i)
            for (int v1 = w1[i]; v1 <= S; ++v1)
                for (int v2 = w2[i]; v2 <= S; ++v2)
                    if (dp[v1 - w1[i]][v2 - w2[i]] != INT_MAX)
                        dp[v1][v2] = min(dp[v1][v2], dp[v1 - w1[i]][v2 - w2[i]] + 1);

        int ans = INT_MAX;
        int t = S * S;
        for (int i = 0; i <= S; ++i)
            for (int j = 0; j <= S; ++j)
                if (i * i + j * j == t && dp[i][j] != INT_MAX)
                    if (ans > dp[i][j])
                        ans = dp[i][j];

        if (ans != INT_MAX)
            printf("%d\n", ans);
        else
            printf("not possible\n");
    }
    return 0;
}