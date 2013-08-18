#include <cstdio>
#include <vector>
#include <algorithm>
#define M 200001
#define EDGE pair < int,int >
using namespace std;

vector < pair < int, EDGE > > GRAPH;
int parent[M], total;
int findset(int x, int *parent);
int Kruskal(int);

int main()
{
    int i, x, y, z, n, m, tc, mc;
    //freopen("in.txt","r",stdin);

    while (scanf("%d%d", &m, &n) && (m | n))
    {
        tc = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            GRAPH.push_back(pair< int, EDGE >(z, EDGE(x, y)));
            tc += z;
        }
        mc = Kruskal(n);

        printf("%d\n", tc - mc);
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
    for (i = 0; i < M; i++)
        parent[i] = i;

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