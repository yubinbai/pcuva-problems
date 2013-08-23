#include<stdio.h>
int n, map[60][60];
void euler(int m)
{
    int i;
    for (i = 1; i <= 50; i++)
        if (map[m][i] > 0)
        {
            --map[m][i];  --map[i][m];
            euler(i);
            printf("%d %d\n", i, m);
        }
}
int main()
{
    int t, f, x, y, i, j, k;
    scanf("%d", &t);
    for (k = 1; k <= t; k++)
    {
        for (i = 0; i <= 50; i++)
            for (j = 0; j <= 50; j++)
                map[i][j] = 0;
        f = 0;
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            ++map[x][0]; ++map[y][0];
            ++map[x][y]; ++map[y][x];
        }
        for (i = 1; i <= 50; i++)
        {
            f = map[i][0] % 2;
            if (f) break;
        }
        printf("Case #%d\n", k);
        if (f) printf("some beads may be lost\n");
        else euler(x);
        if (k < t) printf("\n");
    }
    return 0;
}
