#include <stdio.h>
int dp[800][100][100];
int songs[800];
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int i, j, k, n, t, m, TC;
    int x, y, z;
    scanf("%d", &TC);
    while (TC-- > 0)
    {
        int top = 0;
        scanf("%d %d %d", &n, &t, &m);
        scanf("%d", songs + top++);
        for (i = 1; i < n; i++)
            scanf(", %d", songs + top++);
        for (i = 0; i <= n; i++)
            for (j = 0; j <= m; j++)
                for (k = 0; k <= t; k++)
                    dp[i][j][k] = 0;
        for (i = n - 1; i >= 0; i--)
            for (j = m; j >= 0; j--)
                for (k = t; k >= 0; k--)
                {
                    dp[i][j][k] = dp[i + 1][j][k];
                    if (k >= songs[i])
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i + 1][j][k - songs[i]]);
                    if (j > 0)
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i + 1][j - 1][t - songs[i]]);
                }
        int optimal = 0;
        for (i = 0; i < n; i++)
            optimal = max(optimal, dp[i][m][0]);
        printf("%d\n", optimal);
        if (TC)
            putchar('\n');
    }
    return 0;
}