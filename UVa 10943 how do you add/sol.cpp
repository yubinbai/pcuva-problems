#include <string.h>
#include <stdio.h>
const int MOD = 1000000;
int C[101][101];
void Calc()
{
    int i, j, k;
    for (i = 0; i <= 100; i++) C[i][0] = 0;
    for (j = 0; j <= 100; j++) C[0][j] = 1;
    for (i = 1; i <= 100; i++)
    {
        for (j = 1; j <= 100; j++)
        {
            C[i][j] = 0;
            for (k = 0; k <= i; k++)
                C[i][j] = (C[i][j] % MOD + C[k][j - 1] % MOD) % MOD;
        }
    }
}
int main()
{
    Calc();
    while (true)
    {
        int N, K;
        scanf("%d%d", &N, &K);
        if (!N && !K) break;
        printf("%d\n", C[N][K]);
    }
    return 0;
}