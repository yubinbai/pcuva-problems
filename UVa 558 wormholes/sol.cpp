#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INFINITY 1<<30
using namespace std;
struct node
{
    int u;
    int v;
    int w;
};
int main()
{
    int cases;
    geti(cases);
    while (cases--)
    {
        int n, m, i, j, a, b, c, u, v, w;
        scanf("%d %d", &n, &m);
        node e[m];
        for (i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            e[i].u = a;
            e[i].v = b;
            e[i].w = c;
        }
        int d[n];
        for (i = 0; i < n; i++)
            d[i] = INFINITY;
        d[0] = 0;
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < m; j++)
            {
                u = e[j].u;
                v = e[j].v;
                w = e[j].w;
                if (d[u] + w < d[v])
                    d[v] = d[u] + w;
            }
        }
        int flag = 0;
        for (j = 0; j < m; j++)
        {
            u = e[j].u;
            v = e[j].v;
            w = e[j].w;
            if (d[u] + w < d[v])
            {
                flag = 1;
            }
        }
        if (flag)
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}