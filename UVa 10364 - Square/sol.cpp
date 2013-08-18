#include <stdio.h>
char *res[] = {"no", "yes"};
char dp[4][1 << 20];
int len;
int n;
int max;
int sides[21];
int calculate(int state, int cs)
{
    int i, s = 0;
    for (i = 0; i < n; i++)
        s += (((1 << i)&state) >> i) * sides[i];
    return s - cs * len;
}
char can(int state, int cs)
{
    int l = calculate(state, cs);
    if (l == len)
        return can(state, cs + 1);
    else if (cs == 4)
        return 1;
    else if (dp[cs][state] != -1)
        return dp[cs][state];
    else
    {
        int i;
        char result = 0;
        for (i = 0; i < n && !result; i++)
            if (!(state & (1 << i)) && l + sides[i] <= len)
                result |= can(state | (1 << i), cs);
        return dp[cs][state] = result;
    }
}
int main()
{
    int tc, i, sum;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        max = 1 << n;
        sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", sides + i);
            sum += sides[i];
        }
        if (sum % 4 != 0)
            puts("no");
        else
        {
            len = sum / 4;
            for (i = 0; i < max; i++)
                dp[0][i] = dp[1][i] = dp[2][i] = dp[3][i] = -1;
            puts(res[can(0, 0)]);
        }
    }
    return 0;
}