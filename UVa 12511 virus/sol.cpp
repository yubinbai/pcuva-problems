#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 1010

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, num1[N], num2[N], dp[N], max = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &num1[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &num2[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (num1[i] > num2[j] && max < dp[j])
                    max = dp[j];
                if (num1[i] == num2[j])
                    dp[j] = max + 1;
            }
            max = 0;
        }
        for (int i = 0; i < m; i++)
            max = (max > dp[i] ? max : dp[i]);
        printf("%d\n", max);
    }
}
