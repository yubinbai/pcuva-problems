#include <stdio.h>
int dp[100][4];
int dangerCount(int size, int stacked)
{
    if (!size)
        return dp[size][stacked] = (stacked == 3);
    else if (dp[size][stacked] != -1)
        return dp[size][stacked];
    else
        return dp[size][stacked] =
                   dangerCount(size - 1, (stacked >= 3) ? stacked : 0) +
                   dangerCount(size - 1, (stacked < 3) ? stacked + 1 : stacked);
}
int main()
{
    int i, j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 4; j++)
            dp[i][j] = -1;
    scanf("%d", &i);
    while (i)
    {
        printf("%d\n", dangerCount(i, 0));
        scanf("%d", &i);
    }
    return 0;
}