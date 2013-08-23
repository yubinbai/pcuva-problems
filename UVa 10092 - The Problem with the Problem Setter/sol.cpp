#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1100;
int maze[N][N], pre[N], gap[N], dis[N], cur[N];

int sap (int start, int end, int nodenum)
{
    memset(cur, 0, sizeof(cur));
    memset(gap, 0, sizeof(gap));
    memset(dis, 0, sizeof(dis));
    int u = pre[start] = start, maxflow = 0, aug = -1;
    gap[0] = nodenum;
    while (dis[start] < nodenum)
    {
loop:
        for (int v = cur[u]; v < nodenum; v++)
            if (maze[u][v] && dis[u] == dis[v] + 1)
            {
                if (aug == -1 || aug > maze[u][v]) aug = maze[u][v];
                pre[v] = u;
                u = cur[u] = v;
                if (v == end)
                {
                    maxflow += aug;
                    for (u = pre[u]; v != start; v = u, u = pre[u])
                    {
                        maze[u][v] -= aug;
                        maze[v][u] += aug;
                    }
                    aug = -1;
                }
                goto loop;
            }
        int mindis = nodenum - 1;
        for (int v = 0; v < nodenum; v++)
            if (maze[u][v] && mindis > dis[v])
            {
                cur[u] = v;
                mindis = dis[v];
            }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return maxflow;
}
int a[22][N], num[22];
int main()
{
    int nk, np;
    while (scanf("%d%d", &nk, &np) == 2)
    {
        if (nk == 0 && np == 0) break;
        memset(maze, 0, sizeof(maze));
        int sum = 0;
        for (int i = 1; i <= nk; ++i)
        {
            scanf("%d", &num[i]);
            maze[0][i] = num[i];
            sum += num[i];
        }
        for (int i = nk + 1; i <= nk + np; ++i) maze[i][nk + np + 1] = 1;
        int m, t;
        for (int i = 1; i <= nk; ++i) a[i][0] = 0;
        for (int i = nk + 1; i <= nk + np; i++)
        {
            scanf("%d", &m);
            while (m--)
            {
                scanf("%d", &t);
                a[t][++a[t][0]] = i;
                maze[t][i] = 1;
            }
        }
        if (sap(0, nk + np + 1, nk + np + 2) != sum) printf("0\n");
        else
        {
            printf("1\n");
            for (int i = 1; i <= nk; i++)
            {
                bool first = true;
                for (int j = 1; j <= a[i][0]; ++j)
                {
                    if (maze[i][a[i][j]] == 0)
                    {
                        if (first) first = false;
                        else printf(" ");
                        printf("%d", a[i][j] - nk);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}

