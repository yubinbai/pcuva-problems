#include <cstdio>
#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

struct tuple2
{
    int i, j;
    tuple2(int i, int j) : i(i), j(j) {}
    tuple2() {};
    bool operator == (const  tuple2 &uni)
    {
        return (i == uni.i && j == uni.j);
    }

};

bool visited[1000][1000];
tuple2 parent[1000][1000];
int arr[4][2] = { -1, 0, 0, 1, 1, 0, 0, -1,};
int steps = 0;
int row, column;

void bfs(int start_i, int start_j)
{
    queue <tuple2> q;
    q.push(tuple2(start_i, start_j));
    visited[start_i][start_j] = true;

    while (!q.empty())
    {
        tuple2 v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ti = v.i + arr[k][0];
            int tj = v.j + arr[k][1];

            if (ti >= 0 && ti < row && tj >= 0 && tj < column)
            {
                if (!visited[ti][tj])
                {
                    visited[ti][tj] = true;
                    q.push(tuple2(ti, tj));
                    parent[ti][tj] = tuple2(v);
                    //cout<<v.i<<" "<<v.j<<" is parent of "<< ti << " "<<tj<<endl;
                }
            }
        }
    }

}

void shortest_path(tuple2 start, tuple2 end)
{
    if (start == end || end == tuple2(-1, -1))
    {
    }
    else
    {
        steps++;
        shortest_path(start, parent[end.i][end.j]);

    }

}

int main()
{
    int R, r, numBoms, bomb, starI, starJ, endI, endJ;

    while (scanf("%d%d", &row, &column) && row)
    {
        memset(visited, 0, sizeof(visited));
        scanf("%d", &R);
        for (int i = 0; i < R; i++)
        {
            scanf("%d%d", &r, &numBoms);
            for (int j = 0; j < numBoms; j++)
            {
                scanf("%d", &bomb);
                visited[r][bomb] = true;
                parent[r][bomb] = tuple2(-1, -1);
            }

        }
        scanf("%d%d", &starI, &starJ);
        scanf("%d%d", &endI, &endJ);
        bfs(starI, starJ);
        shortest_path(tuple2 (starI, starJ), tuple2 (endI, endJ));
        printf("%d\n", steps);
        steps = 0;

    }
    return 0;
}
