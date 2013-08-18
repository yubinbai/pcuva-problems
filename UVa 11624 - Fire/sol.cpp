#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
static char **map, * *v;
static int **f;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
using namespace std;
int solve(int r, int c)
{
    queue<int> Q1;
    queue<int> Q2;
    int i, j, a, b, d, t;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            f[i][j] = -1;
            v[i][j] = 0;
            if (map[i][j] == 'F')
            {
                Q1.push(i);
                Q1.push(j);
                f[i][j] = 0;
            }
            else if (map[i][j] == 'J')
            {
                Q2.push(i);
                Q2.push(j);
                Q2.push(0);
                v[i][j] = 1;
            }
        }
    while (!Q1.empty())
    {
        i = Q1.front();
        Q1.pop();
        j = Q1.front();
        Q1.pop();
        for (d = 0; d < 4; d++)
        {
            a = i + dx[d];
            b = j + dy[d];
            if (a >= 0 && a < r && b >= 0 && b < c && map[a][b] != '#'
                    && f[a][b] == -1)
            {
                f[a][b] = f[i][j] + 1;
                Q1.push(a);
                Q1.push(b);
            }
        }
    }
    while (!Q2.empty())
    {
        i = Q2.front();
        Q2.pop();
        j = Q2.front();
        Q2.pop();
        t = Q2.front();
        Q2.pop();
        if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
            return t + 1;
        else
            for (d = 0; d < 4; d++)
            {
                a = i + dx[d];
                b = j + dy[d];
                if (a >= 0 && a < r && b >= 0 && b < c && (f[a][b] == -1
                        || f[a][b] > t + 1) && map[a][b] != '#' && !v[a][b])
                {
                    v[a][b] = 1;
                    Q2.push(a);
                    Q2.push(b);
                    Q2.push(t + 1);
                }
            }
    }
    return -1;
}
int main()
{
    int i, j, r, c, runs, res;
    f = (int **) malloc(1200 * sizeof(int *));
    map = (char **) malloc(1200 * sizeof(char *));
    v = (char **) malloc(1200 * sizeof(char *));
    for (i = 0; i < 1200; i++)
    {
        f[i] = (int *) malloc(1200 * sizeof(int));
        map[i] = (char *) malloc(1200);
        v[i] = (char *) malloc(1200);
    }
    scanf("%d\n", &runs);
    while (runs-- > 0)
    {
        scanf("%d %d\n", &r, &c);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
                map[i][j] = getchar();
            getchar();
        }
        res = solve(r, c);
        if (res == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", res);
    }
    return 0;
}