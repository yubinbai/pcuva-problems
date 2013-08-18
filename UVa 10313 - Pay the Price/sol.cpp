#include <stdio.h>
#define N 305;
#define min(a,b)(a<b)?a:b
unsigned long long int sum[305][305];
unsigned long long int res[305][305];
int main()
{
    int i, j, k, tokens;
    char inp[100];
    for (i = 0; i < 305; i++)
        for (j = 0; j < 305; j++)
            res[i][j] = 0;
    res[0][0] = 1;
    for (i = 1; i <= 300; i++)
        for (j = i; j <= 300; j++)
            for (k = 1; k <= 300; k++)
                res[j][k] += res[j - i][k - 1];
    for (i = 0; i < 305; i++)sum[0][i] = res[0][i];
    for (i = 0; i < 305; i++)
        for (j = 1; j < 305; j++)
            sum[i][j] = res[i][j] + sum[i][j - 1];
    while (gets(inp))
    {
        tokens = sscanf(inp, "%d %d %d", &i, &j, &k);
        if (tokens == 1)
            printf("%llu\n", sum[i][i]);
        else if (tokens == 2)
            printf("%llu\n", sum[i][min(j, i)]);
        else if (j <= i)
            printf("%llu\n", sum[i][min(k, i)] - sum[i][j] + res[i][j]);
        else puts("0");
    }
    return 0;
}