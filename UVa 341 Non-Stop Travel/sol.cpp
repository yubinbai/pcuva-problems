#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 1e9

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi p;
int dist[10];
vector<vii> AdjList;
int c, V, b, w, s, t, cas = 1;
priority_queue<ii, vector<ii>, greater<ii> > pq;

void printPath(int t)
{
    if (t == s)
        printf("%d", s + 1);
    else
    {
        printPath(p[t]);
        printf(" %d", t + 1);
    }
}

void init()
{
    for (int i = 0 ; i < 10 ; i++)
        dist[i] = INF;
}

int dijkstra()
{
    pq = priority_queue<ii, vector<ii>, greater<ii> >();
    init();
    pq.push(ii(0, s));
    dist[s] = 0;
    while (!pq.empty())
    {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (u == t) return d;
        if (dist[u] == d)
        {
            for (int i = 0 ; i < AdjList[u].size() ; i++)
            {
                ii v = AdjList[u][i];
                if (dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second;
                    p[v.first] = u;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
    }
}

int main()
{
    while (scanf("%d", &V), V)
    {
        AdjList.assign(V, vii());
        for (int i = 0 ; i < V ; i++)
        {
            scanf("%d", &c);
            while (c--)
            {
                scanf("%d %d", &b, &w);
                b--;
                AdjList[i].push_back(ii(b, w));
            }
        }
        p.assign(V, 0);
        scanf("%d %d", &s, &t);
        s--, t--;
        dijkstra();
        printf("Case %d: Path = ", cas++);
        printPath(t);
        printf("; %d second delay\n", dist[t]);
    }
}