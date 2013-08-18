#include <algorithm>
#include <limits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

vector<map<int, int> > graph;
vector<int> dijkstraD, dijkstraP;

void dijkstra(int s)
{
    dijkstraD = vector<int>(graph.size(), numeric_limits<int>::max());
    dijkstraP = vector<int>(graph.size(), -1);
    priority_queue<pair<int, int> > q;
    dijkstraP[s] = -s - 1;
    dijkstraD[s] = 0;
    q.push(make_pair(dijkstraD[s], s));
    while (!q.empty())
    {
        pair<int, int> p = q.top();
        q.pop();
        if (dijkstraP[p.second] < 0)
        {
            dijkstraP[p.second] = -dijkstraP[p.second] - 1;
            for (map<int, int>::iterator itr = graph[p.second].begin();
                    itr != graph[p.second].end(); ++itr)
                if (dijkstraP[itr->first] < 0
                        && dijkstraD[p.second] + graph[p.second][itr->first] < dijkstraD[itr->first])
                {
                    dijkstraP[itr->first] = -p.second - 1;
                    dijkstraD[itr->first] = dijkstraD[p.second] + graph[p.second][itr->first];
                    q.push(pair<int, int>(-dijkstraD[itr->first], itr->first));
                }
        }
    }
}

int main()
{
    int n, k, t[8], K = 100;
    char line[1024], *p;
    while (scanf("%d %d", &n, &k) == 2)
    {
        // build graph
        graph.clear();
        // nodes
        for (int i = n * K; i > -1; --i)
            graph.push_back(map<int, int>());
        // elevator speed
        for (int i = 0; i < n; ++i)
            scanf("%d", &t[i]);
        // changing elevators cost
        for (int i = 1; i < n; ++i)
            graph[K * (i - 1)][K * i] = graph[K * i][K * (i - 1)] = 0;
        for (int j = 1; j < K; ++j)
            for (int i = 0; i < n; ++i)
                for (int i2 = 0; i2 < n; ++i2)
                    if (i != i2)
                        graph[K * i + j][K * i2 + j] = 60;
        // elevator stop
        gets(line);
        for (int i = 0; i < n; ++i)
        {
            int prev, cur;
            gets(line);
            p = strtok(line, " ");
            sscanf(p, "%d", &prev);
            while ((p = strtok(NULL, " ")))
            {
                sscanf(p, "%d", &cur);
                graph[K * i + prev][K * i + cur] =
                    graph[K * i + cur][K * i + prev] =
                        t[i] * abs(cur - prev);
                prev = cur;
            }
        }
        //
        int d = numeric_limits<int>::max();
        dijkstra(0);
        for (int i = 0; i < n; ++i)
            d = min(d, dijkstraD[K * i + k]);
        if (d == numeric_limits<int>::max())
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", d);
    }
    return 0;
}