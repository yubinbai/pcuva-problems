#include <stdio.h>
int dp[32];
int solve(int n)
{
    if (dp[n] != -1)
        return dp[n];
    else
    {
        int i;
        int res = 3 * solve(n - 2);
        for (i = 4; i <= n; i += 2)
            res += 2 * solve(n - i);
        return dp[n] = res;
    }
}
int main()
{
    int i;
    for (i = 0; i < 32; i += 2)
        dp[i] = -1;
    for (i = 1; i < 32; i += 2)
        dp[i] = 0;
    dp[0] = 1;
    scanf("%d", &i);
    while (i != -1)
    {
        printf("%d\n", solve(i));
        scanf("%d", &i);
    }
    return 0;
}