#include <stdio.h>
#define max(a,b) (a>b)?a:b
int sum[100][100];
int inf = 1 << 25;
int SUM(int si, int sj, int ei, int ej)
{
    int res = sum[ei][ej];
    if (sj - 1 >= 0)
        res -= sum[ei][sj - 1];
    if (si - 1 >= 0)
        res -= sum[si - 1][ej];
    if (si - 1 >= 0 && sj - 1 >= 0)
        res += sum[si - 1][sj - 1];
    return res;
}
int main()
{
    int i, j, y, x, N, s, M, b, m, c, A, B;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &s);
        N = M = s;
        for (i = 0; i < s; i++)
            for (j = 0; j < s; j++)
                sum[i][j] = 0;
        scanf("%d", &b);
        while (b--)
        {
            scanf("%d %d %d %d", &i, &j, &y, &x);
            A = i - 1;
            B = j - 1;
            for (i = A; i <= y - 1; i++)
                for (j = B; j <= x - 1; j++)
                    sum[i][j] = 1;
        }
        for (i = 0; i < N; i++)
            for (j = 1; j < M; j++)
                sum[i][j] += sum[i][j - 1];
        for (i = 0; i < M; i++)
            for (j = 1; j < N; j++)
                sum[j][i] += sum[j - 1][i];
        m = 0;
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++)
                for (y = i; y < N; y++)
                    for (x = j; x < M; x++)
                        if (!SUM(i, j, y, x))
                            m = max(m, (y - i + 1) * (x - j + 1));
        printf("%d\n", m);
    }
    return 0;
}