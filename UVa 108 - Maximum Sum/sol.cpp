#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 102
using namespace std;

int arr[MAXN][MAXN], sum[MAXN][MAXN];

int mx, sm;
int main()
{
    int T, m, n, x, y;
    int i, j;

    while (~scanf("%d", &n))
    {
        memset(sum, 0, sizeof(sum));
        memset(arr, 0, sizeof(arr));

        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= n; ++j)
            {
                scanf("%d", &arr[i][j]);
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
            }
        }
        int maxSum = -2147483645;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int t, min;
                min = 0;
                for (int k = 1; k <= n; ++k)
                {
                    t = sum[i][k] - sum[j][k] - min;
                    if (t > maxSum) maxSum = t;
                    if (sum[i][k] - sum[j][k] < min)
                        min = sum[i][k] - sum[j][k];
                }
            }
        }
        printf("%d\n", maxSum);
    }
    return 0;
}