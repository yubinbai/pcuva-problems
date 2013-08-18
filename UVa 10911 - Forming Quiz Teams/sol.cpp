#include <stdio.h>
#include <math.h>
#define min(a,b) (a<b)?a:b
int max;
int n;
int x[20];
int y[20];
double dist[20][20], dp[1 << 16];
char name[20];
double minD(int state)
{
    if (state == max)
        return 0;
    else if (dp[state] != -1)
        return dp[state];
    else
    {
        int i, j;
        double m = 1 << 30;
        for (i = 0; i < 2 * n; i++)
            if (!(state & (1 << i)))
                for (j = i + 1; j < 2 * n; j++)
                    if (!(state & (1 << j)))
                        m = min(m, dist[i][j] + minD(state | (1 << i) | (1 << j)));
        return dp[state] = m;
    }
}
int main()
{
    int i, j, cc = 1;
    scanf("%d", &n);
    while (n)
    {
        max = (1 << (2 * n)) - 1;
        for (i = 0; i < 2 * n; i++)
            scanf("%s %d %d", name, x + i, y + i);
        for (i = 0; i < 2 * n; i++)
            for (j = i + 1; j < 2 * n; j++)
                dist[i][j] = dist[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        for (i = 0; i <= max; i++)
            dp[i] = -1;
        printf("Case %d: %.2lf\n", cc++, minD(0));
        scanf("%d", &n);
    }
    return 0;
}