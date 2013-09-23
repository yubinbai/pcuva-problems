#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL f, a, b;
int e;
LL x[110], y[110];
vector<int> start;
int end[110], vis[110];
vector<int> g[110];
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
int china(int p1, int p2)
{
    LL M = x[p1] * x[p2];
    LL ans = 0, d, q, w;
    w = M / x[p1];
    exgcd(x[p1], w, d, d, q);
    ans = (ans + w * q * (y[p1] % x[p1])) % M;
    w = M / x[p2];
    exgcd(x[p2], w, d, d, q);
    ans = (ans + w * q * (y[p2] % x[p2])) % M;
    while (ans < f)
    {
        if (ans >= y[p1] && ans >= y[p2]) return 1;
        ans += M;
    }
    return 0;
}
int judge(int p1, int p2)
{
    if (y[p1] < y[p2]) swap(p1, p2);
    LL g = x[p2] * gcd(x[p1], x[p2]);
    LL i = 0;
    while (y[p1] + i * x[p1] < f && i < g)
    {
        if ((y[p1] - y[p2] + i * x[p1]) % x[p2] == 0) return 1;
        i++;
    }
    return 0;
}
int dfs(int u)
{
    vis[u] = 1;
    if (end[u]) return 1;
    int ans = 0;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!vis[v]) ans |= dfs(v);
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        start.clear();
        memset(end, 0, sizeof(end));
        cin >> f >> e >> a >> b;
        for (int i = 0; i < e; i++) g[i].clear();
        for (int i = 0; i < e; i++) cin >> x[i] >> y[i];
        for (int i = 0; i < e; i++)
        {
            if (a >= y[i] && (a - y[i]) % x[i] == 0) start.push_back(i);
            if (b >= y[i] && (b - y[i]) % x[i] == 0) end[i] = 1;
        }
        for (int i = 0; i < e; i++)
        {
            for (int j = 0; j < e; j++)
            {
                if (i == j) continue;
                if (gcd(x[i], x[j]) == 1)
                {
                    if (china(i, j))
                    {
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
                else
                {
                    if (judge(i, j))
                    {
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < start.size(); i++)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(start[i]))
            {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "It is possible to move the furniture." << endl;
        else cout << "The furniture cannot be moved." << endl;
    }
    return 0;
}