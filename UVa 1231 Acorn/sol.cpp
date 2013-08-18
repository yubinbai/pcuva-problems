#include <stdio.h>
int acorns[2005][2005];
int dp[2005];
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int tc;
    int h, n, f;
    scanf("%d", &tc);
    while (tc--)
    {
        int i, j;
        scanf("%d %d %d", &n, &h, &f);
        for (i = 0; i <= n; i++)
            for (j = 0; j <= h + 1; j++)
                dp[j] = acorns[i][j] = 0;
        for (i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            for (j = 0; j < k; j++)
            {
                int loc;
                scanf("%d", &loc);
                acorns[i][loc]++;
            }
        }
        for (i = h; i >= 0; i--)
            for (j = 0; j < n; j++)
            {
                acorns[j][i] += max(acorns[j][i + 1], ((f + i) <= h) ? dp[i + f] : 0);
                dp[i] = max(dp[i], acorns[j][i]);
            }
        printf("%d\n", dp[0]);
    }
    return 0;
}