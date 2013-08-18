#include <stdio.h>
#define inf  100000000
static int winds[10][1005];
static unsigned int memo[10][1005];
int min(int a, int b)
{
    return (a < b) ? a : b;
}
unsigned int fuel(int y, int x, int n)
{
    if (x == n && !y)
        return 0;
    else if (x == n || y < 0 || y > 9)
        return inf;
    else if (memo[y][x] != -1)
        return memo[y][x];
    else if (y == 0)
    {
        if (x == n - 1)
            return memo[y][x] = min(min(60 - winds[y][x] + fuel(y + 1, x + 1, n), 20 - winds[y][x] + fuel(y - 1, x + 1, n)), 30 - winds[y][x] + fuel(y, x + 1, n));
        else return memo[y][x] =  min(60 - winds[y][x] + fuel(y + 1, x + 1, n), 20 - winds[y][x] + fuel(y - 1, x + 1, n));
    }
    else
        return memo[y][x] = min(min(60 - winds[y][x] + fuel(y + 1, x + 1, n), 20 - winds[y][x] + fuel(y - 1, x + 1, n)), 30 - winds[y][x] + fuel(y, x + 1, n));

}
int main()
{
    int c, n, j, i;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        n = n / 100;
        for (i = 9; i >= 0; i--)
            for (j = 0; j < n; j++)
            {
                scanf("%d", winds[i] + j);
                memo[i][j] = -1;
            }
        printf("%u\n\n", fuel(0, 0, n));
    }
    return 0;
}