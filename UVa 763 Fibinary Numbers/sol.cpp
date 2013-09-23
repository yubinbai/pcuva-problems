#include<stdio.h>
#include<string.h>
#define MAXD 150
char a[MAXD], b[MAXD];
int ans[MAXD];
void solve()
{
    int i, j, k;
    memset(ans, 0, sizeof(ans));
    k = strlen(a) - 1;
    for (i = k, j = 0; i >= 0; i --, j ++)
        ans[j] += a[i] - '0';
    k = strlen(b) - 1;
    for (i = k, j = 0; i >= 0; i --, j ++)
        ans[j] += b[i] - '0';
    for (;;)
    {
        for (i = 0; i < 110; i ++)
        {
            if (ans[i] && ans[i + 1])
            {
                -- ans[i];
                -- ans[i + 1];
                ++ ans[i + 2];
                break;
            }
            else if (ans[i] > 1)
            {
                ans[i] -= 2;
                if (i == 0)
                    ++ ans[i + 1];
                else if (i == 1)
                {
                    ++ ans[i + 1];
                    ++ ans[i - 1];
                }
                else
                {
                    ++ ans[i + 1];
                    ++ ans[i - 2];
                }
                break;
            }
        }
        if (i == 110)
            break;
    }
    for (i = 110; i > 0; i --)
        if (ans[i])
            break;
    for (; i >= 0; i --)
        printf("%d", ans[i]);
    printf("\n");
}
int main()
{
    int t = 0;
    while (scanf("%s%s", a, b) == 2)
    {
        if (t ++)
            printf("\n");
        solve();
    }
    return 0;
}