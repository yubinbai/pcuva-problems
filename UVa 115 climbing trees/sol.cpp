#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair< string, int > psi;
const int MAX = 1024;
const int LOG = 10;
map< string, int > M;
map< string, int > :: iterator it;
vector< int > G[MAX];
int vis[MAX], L[MAX], T[MAX], P[MAX][LOG], stck[MAX], top;
inline int hash(char *s, int &n)
{
    int ret; it = M.find(s);
    if (it == M.end()) M.insert(psi(s, ret = n++));
    else ret = it->second;
    return ret;
}
void topo(int u)
{
    int i, v, sz = G[u].size();
    vis[u] = 1;
    for (i = 0; i < sz; i++)
    {
        v = G[u][i];
        if (!vis[v]) topo(v);
    }
    stck[top++] = u;
}
void dfs(int u, int p, int d)
{
    int i, v, sz = G[u].size();
    T[u] = p, L[u] = d, vis[u] = 2;
    for (i = 0; i < sz; i++)
    {
        v = G[u][i];
        if (vis[v] != 2) dfs(v, u, d + 1);
    }
}
void preprocess(int n)
{
    int i, j;
    memset(P, -1, sizeof P);
    for (i = 0; i < n; i++) P[i][0] = T[i];
    for (j = 1; (1 << j) < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (P[i][j - 1] != -1) P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}
int lca(int p, int q)
{
    int lg, i;
    if (L[p] < L[q]) swap(p, q);
    for (lg = 1; (1 << lg) <= L[p]; lg++); lg--;
    for (i = lg; i >= 0; i--)
    {
        if (L[p] - (1 << i) >= L[q])
        {
            p = P[p][i];
        }
    }
    if (p == q) return p;
    for (i = lg; i >= 0; i--)
    {
        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            p = P[p][i];
            q = P[q][i];
        }
    }
    return T[p];
}
int main()
{
    char name1[32], name2[32];
    int n = 0, u, v, anc, i, j, k, ud, vd, lvl;
    //freopen("in2.txt", "r", stdin);
    while (scanf("%s %s", name1, name2) == 2)
    {
        if (!strcmp(name1, "no.child")) break;
        u = hash(name1, n);
        v = hash(name2, n);
        G[v].push_back(u);
    }
    for (u = top = 0; u < n; u++) if (!vis[u]) topo(u);
    while (top--)
    {
        u = stck[top];
        if (vis[u] != 2) dfs(u, -1, 0);
    }
    preprocess(n);
    while (scanf("%s %s", name1, name2) == 2)
    {
        it = M.find(name1);
        if (it == M.end())
        {
            puts("no relation");
            continue;
        }
        else u = it->second;
        it = M.find(name2);
        if (it == M.end())
        {
            puts("no relation");
            continue;
        }
        else v = it->second;
        if (u == v) puts("sibling");
        else if (T[u] == v) puts("child");
        else if (T[v] == u) puts("parent");
        else
        {
            anc = lca(u, v);
            if (anc == -1) puts("no relation");
            else if (anc == u)
            {
                lvl = L[v] - L[u];
                for (i = 0; i < lvl - 2; i++) printf("great ");
                printf("grand parent\n");
            }
            else if (anc == v)
            {
                lvl = L[u] - L[v];
                for (i = 0; i < lvl - 2; i++) printf("great ");
                printf("grand child\n");
            }
            else
            {
                ud = L[u] - L[anc] - 1;
                vd = L[v] - L[anc] - 1;
                k = min(ud, vd);
                j = abs(ud - vd);
                if (!k && !j) puts("sibling");
                else if (!j) printf("%d cousin\n", k);
                else printf("%d cousin removed %d\n", k, j);
            }
        }
    }
    return 0;
}