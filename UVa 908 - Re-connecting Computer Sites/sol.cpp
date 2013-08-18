#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1000020
#define EDGE pair < int,int >
using namespace std;

vector < pair < int, EDGE > > GRAPH;
int parent[MAX], total;
int findset(int x, int *parent);
int Kruskal(int);

int main()
{
    int i, j, k, x, y, z, n, m, cc, nc, mc, f = 1;
    //freopen("in.txt","r",stdin);

    while (scanf("%d", &n) == 1)
    {
        cc = 0;
        for (i = 1; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            cc += z;
        }

        mc = MAX;
        scanf("%d", &k);
        for (i = 0; i < k; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            GRAPH.push_back(pair< int, EDGE >(z, EDGE(x, y)));
        }

        scanf("%d", &m);
        for (j = 0; j < m; j++)
        {
            scanf("%d%d%d", &x, &y, &z);
            GRAPH.push_back(pair< int, EDGE >(z, EDGE(x, y)));
        }
        //Reading I/P is finishes here
        n = m + k;
        for (i = 1; i < n; i++)
            parent[i] = i;

        nc = Kruskal(m + k);

        if (f)
        {
            f = 0;
            printf("%d\n%d\n", cc, nc);
        }
        else
            printf("\n%d\n%d\n", cc, nc);
        GRAPH.clear();
    }
    return 0;
}

int findset(int x, int *parent)
{
    if (x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

int Kruskal(int e)
{
    int i, pu, pv, total = 0;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for (i = 0; i < e; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if (pu != pv)
        {
            total += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
    return total;
}
