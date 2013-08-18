#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int graph[210][210];
int n;
int dist[210];

/*
    check if a graph is bicolorable / bipartite
    assumption:
    1. no node will have an edge to itself
    2. the graph is nondirected
    3. the graph will be strongly connected
*/
void bicolorable()
{
    int node = 0;
    dist[node] = 1;
    queue<int> q;

    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        for (int to = 0; to < n; to++)
            if (graph[node][to])
            {
                if (!dist[to])
                {
                    dist[to] = 3 - dist[node];
                    q.push(to);
                }
                else if (dist[to] == dist[node])
                {
                    cout << "NOT BICOLORABLE." << endl;
                    return ;
                }
            }
    }

    cout << "BICOLORABLE." << endl;

}

int main(int argc, char const *argv[])
{
    while (cin >> n && n)
    {
        memset(graph, 0, sizeof(graph));
        memset(dist, 0, sizeof(dist));

        int l;
        cin >> l;
        while (l--)
        {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        bicolorable();
    }
    return 0;
}