#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <deque>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
#define rep(i,init,end) for(int i=init;i<end;i++)
#define rem(i,init,end) for(int i=init;i>=end;i--)

#define pb push_back
#define ppb pop_back
#define ps push

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define eps 1e-9
#define inf (1<<29)

#define Clear(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define si(a)   scanf("%d",&a)
#define sii(a,b)    scanf("%d %d",&a,&b)
#define M 200000 + 10

struct edge
{
    int u, v, w;
    bool operator < ( const edge &p ) const
    {
        return w < p.w;
    }
};

vector < edge > GRAPH;
int parent[M];

int find(int x)
{
    if (parent[x] == x)    return x;
    return parent[x] = find(parent[x]);
}

int mst(int n, int m)
{
    sort(GRAPH.begin(), GRAPH.end());

    int i, u, v, total = 0;
    for (i = 0; i < n + 2; i++)    parent[i] = i;

    for (i = 0; i < m; i++)
    {
        u = find(GRAPH[i].u);
        v = find(GRAPH[i].v);
        if (u != v)
        {
            total += GRAPH[i].w;
            parent[u] = parent[v];
        }
    }
    return total;
}

void reset(int n)
{
    GRAPH.clear();
    Clear(parent);
    rep(i, 0, n + 1)    parent[i] = i;
}

int main()
{
    int i, u, v, w, n, m, total;
    while (sii(n, m) && (m | n))
    {
        reset(n);
        total = 0;
        for (i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge get;
            get.u = u; get.v = v; get.w = w;
            GRAPH.pb(get);
            total += w;
        }
        printf("%d\n", total - mst(n, m));
    }
}