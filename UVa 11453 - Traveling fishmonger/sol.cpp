#include <cstdio>
#include <utility>
#include <memory.h>
#include <queue>
#include <climits>
using namespace std;

int const MAXN = 55;
int const MAXT = 1005;
int const BIG_NUM = INT_MAX / 2;

struct state
{
    state() {}
    state(int i, int t, int _t)
        : index(i), toll(t), time(_t) {}
    bool operator < (const state &s) const
    {
        if (toll != s.toll)
            return toll > s.toll;
        return time > s.time;
    }
    int index, toll, time;
};

int cost[MAXN][MAXN];
int T[MAXN][MAXN];
bool visited[MAXN][MAXT];
int dist[MAXN][MAXT];

pair<int, int> solve(int src, int trg, int &nodes, int &total_time)
{
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < nodes; ++i)
        for (int j = 0; j < MAXT; ++j)
            dist[i][j] = BIG_NUM;
    dist[src][0] = 0;
    priority_queue<state> q;
    for (q.push(state(src, 0, 0)); !q.empty();)
    {
        int index = q.top().index;
        int cur_cost = q.top().toll;
        int cur_time = q.top().time;
        q.pop();
        if (index == trg)
            return make_pair(cur_cost, cur_time);
        if (visited[index][cur_time])
            continue;
        visited[index][cur_time] = true;
        for (int i = 0; i < nodes; ++i)
            if (i != index)
            {
                int new_time = cur_time + T[index][i];
                if (new_time <= total_time)
                {
                    int new_cost = cur_cost + cost[index][i];
                    if (new_cost < dist[i][new_time])
                    {
                        dist[i][new_time] = new_cost;
                        q.push(state(i, new_cost, new_time));
                    }
                }
            }
    }
    return make_pair(-1, -1);
}

int main(int argc, char **args)
{
    for (int n, t; scanf("%d%d", &n, &t);)
    {
        if (n == 0 && t == 0)
            break;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &T[i][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &cost[i][j]);
        pair<int, int> result = solve(0, n - 1, n, t);
        printf("%d %d\n", result.first, result.second);
    }
    return 0;
}