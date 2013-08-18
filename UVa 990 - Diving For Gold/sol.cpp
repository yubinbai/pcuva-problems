#include <stdio.h>
#define max(a,b) (a>b)?a:b
int value[35], weight[35], dp[1005][35];
char taken[1005][35];
char mark[35];
int maxGold(int t, int n)
{
    if (!t || n < 0)
        return 0;
    else if (dp[t][n] != -1)
        return dp[t][n];
    else
    {
        int a = (t >= weight[n]) ? (value[n] + maxGold(t - weight[n], n - 1)) : 0;
        int b = maxGold(t, n - 1);
        taken[t][n] = (a > b);
        return dp[t][n] = max(a, b);
    }
}
int main()
{
    int t, w, n, i, j, count, bl;
    bl = 0;
    while (scanf("%d %d", &t, &w) == 2)
    {
        if (bl)
            putchar('\n');
        bl = 1;
        scanf("%d", &n);
        i = 0;
        while (i < n)
        {
            scanf("%d %d", weight + i, value + i);
            weight[i] = 3 * w * weight[i];
            i++;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= t; j++)
            {
                dp[j][i] = -1;
                taken[j][i] = 0;
            }
            mark[i] = 0;
        }
        printf("%d\n", maxGold(t, n - 1));
        i = n - 1;
        j = t;
        count = 0;
        while (i >= 0)
        {
            if (taken[j][i])
            {
                mark[i] = 1;
                count++;
                j = j - weight[i];
            }
            i--;
        }
        printf("%d\n", count);
        for (i = 0; i < n; i++)
            if (mark[i])
                printf("%d %d\n", weight[i] / 3 / w, value[i]);

    }
    return 0;
}