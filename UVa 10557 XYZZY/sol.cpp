#include<stdio.h>
#include<string.h>
using namespace std;

#define N 105
int n, value[N], map[N][N];
int vis[N], energy[N];
int que[N];

int BFS(int k)
{
    memset(vis, 0, sizeof(vis));
    memset(que, 0, sizeof(que));
    int front, end;
    front = end = 0;
    vis[k] = 1;
    que[end++] = k;
    while (front < end)
    {
        int now = que[front++];
        for (int i = 1; i <= n; i++)
        {
            if (map[now][i] && !vis[i])
            {
                if (i == n)
                    return 1;
                que[end++] = i;
                vis[i] = 1;
            }
        }
    }
    return 0;
}

int DFS(int k, int sum)
{
    if (k == n)
        return 1;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (map[k][i] && sum + value[i] > 0)
            {
                if (!energy[i])
                {
                    energy[i] = sum + value[i];
                    if (DFS(i, energy[i]))
                        return 1;
                }
                else if (sum + value[i] > energy[i] && BFS(i))
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{

    int a, m;
    while (scanf("%d", &n), n >= 0)
    {
        // Init.
        memset(value, 0, sizeof(value));
        memset(map, 0, sizeof(map));
        memset(energy, 0, sizeof(energy));

        // Read.
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &value[i], &m);
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a);
                map[i][a] = 1;
            }
        }

        // Find.
        if (DFS(1, 100))
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}