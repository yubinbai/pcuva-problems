#include <stdio.h>
#include <math.h>
int map[20][20];
char v[20][20];
int solve(int i, int j, int n, int r)
{
    if (!v[i][j] && i >= r && j >= r && i < n - r && j < n - r)
    {
        v[i][j] = 1;
        if (i == r && j < n - r - 1)
            return map[i][j] + solve(i, j + 1, n, r);
        else if (j == n - r - 1 && i < n - r - 1)
            return map[i][j] + solve(i + 1, j, n, r);
        else if (j <= n - r - 1 && i == n - r - 1 && j > r)
            return map[i][j] + solve(i, j - 1, n, r);
        else
            return map[i][j] + solve(i - 1, j, n, r);
    }
    return 0;
}
int main()
{
    int i, j, n, c;
    c = 1;
    scanf("%d", &n);
    while (n)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                scanf("%d", map[i] + j);
                v[i][j] = 0;
            }
        j = ceil(n / 2);
        printf("Case %d:", c++);
        for (i = 0; i < j + (n & 1); i++)
            printf(" %d", solve(i, i, n, i));
        putchar('\n');
        scanf("%d", &n);
    }
    return 0;
}