#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int vis[210], N, M, G[210][210], inDegree[210], outDegree[210];

void dfs(int v)
{
    vis[v] = true;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i] && G[v][i])
        {
            dfs(i);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while (~scanf("%d %d", &N, &M))
    {
        memset(G, 0, sizeof(G));
        int a, b;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < M; ++i)
        {
            scanf("%d %d", &a, &b);
            G[a][b] = G[b][a] = 1;
            ++vis[a];
            ++vis[b];
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            if (vis[i] % 2 == 1)
            {
                ++cnt;
                break;
            }
        }
        memset(vis, 0, sizeof(vis));
        if (cnt || M < 2) printf("Not Possible\n");
        else
        {
            dfs(0);
            bool flag = true;
            for (int i = 0; i < N; ++i)
            {
                if (!vis[i]) flag = false;
            }
            if (flag)printf("Possible\n");
            else printf("Not Possible\n");
        }

    }
    return 0;
}