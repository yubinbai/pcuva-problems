#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN    25
#define MAXM    25
int G[MAXN][MAXN], vis[MAXN][MAXN];
int ans;
int n, m;
void dfs(int u, int len)
{
    if (len > ans) ans = len;
    for (int v = 0; v < n; v++)
        if (G[u][v] && !vis[u][v])
        {
            vis[u][v] = vis[v][u] = 1;
            dfs(v, len + 1);
            vis[u][v] = vis[v][u] = 0;
        }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    while (cin >> n >> m && (n != 0 || m != 0))
    {
        int i;
        memset(G, 0, sizeof(G));
        for (i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            G[a][b] = G[b][a] = 1;
        }
        ans = 0;
        for (i = 0; i < n; i++)
            dfs(i, 0);
        printf("%d\n", ans);
    }
    return 0;
}