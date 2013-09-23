#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#define inf 1<<23
using namespace std;
vector<int> g[10010];
int n;
int dp[10010][20];
void dfs(int u, int f)
{
    int i, j, k;
    if (g[u].size())
    {
        for (i = 1; i <= 15; i++)
        {
            dp[u][i] = i;
        }
        for (i = 0; i < g[u].size(); i++)
        {
            int y = g[u][i];
            if (y == f) continue;
            dfs(y, u);
            for (j = 1; j <= 15; j++)
            {
                int temp = inf;
                for (k = 1; k <= 15; k++)
                {
                    if (k == j) continue;
                    temp = min(temp, dp[y][k]);
                }
                dp[u][j] += temp;
            }
        }
    }
    else
    {
        for (i = 1; i <= 15; i++)
        {
            dp[u][i] = i;
        }
    }
}
int main()
{
    int i, j;
    int T;
    while ( scanf("%d", &n) == 1 && n)
    {
        for (i = 0; i < n; i++)
        {
            g[i].clear();
        }
        getchar();
        for (i = 0; i < n; i++)
        {
            string str;
            stringstream ss;
            getline(cin, str);
            char c;
            ss << str;
            int u, v;
            ss >> u;
            ss >> c;
            while (ss >> v)
            {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        dfs(0, -1);
        int ans = inf;
        for (i = 1; i <= 15; i++)
        {
            ans = min(ans, dp[0][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}