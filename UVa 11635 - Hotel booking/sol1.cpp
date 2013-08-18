#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#define MAX 1<<29
using namespace std;

typedef struct List
{
    int y, z;
} LIST;

LIST p;
int N, K, hotel[105], d[10005], top;
bool is[10005], visit[10005];
vector <List> v[10005];
vector <int> g[10005];

void SPFA(int VV);
void SPFA2(int VV);
void create(int VV);

main()
{

    int k, n, i, j, a, b, c, M, m;
    while (scanf(" %d", &N) == 1 && N)
    {
        scanf(" %d", &K);
        memset(is, 0, sizeof(is));
        for (k = top = 0; k < K; k++)
        {
            scanf(" %d", &i);
            hotel[top++] = i;
            is[i] = true;
        }
        for (n = 0; n <= N; n++)
            v[n].clear();
        for (i = 0; i <= N; i++)
            g[i].clear();
        scanf(" %d", &M);
        for (m = 0; m < M; m++)
        {
            scanf(" %d %d %d", &a, &b, &c);
            p.y = b;
            p.z = c;
            v[a].push_back(p);
            p.y = a;
            p.z = c;
            v[b].push_back(p);
        }
        SPFA(1);
        create(1);

        SPFA(N);
        create(N);
        for (i = 0; i < top; i++)
        {
            SPFA(hotel[i]);
            create(hotel[i]);
        }
        SPFA2(1);
        if (d[N] != MAX)
            printf("%d\n", d[N] - 1);
        else
            printf("-1\n");
    }
}
void SPFA(int VV)
{
    int i, j, n, k;
    for (n = 0; n <= N; n++)
    {
        d[n] = MAX;
        visit[n] = false;
    }
    d[VV] = 0;
    visit[VV] = true;
    queue <int> q;
    q.push(VV);
    while (!q.empty())
    {
        k = q.front();
        visit[k] = false;
        q.pop();
        for (i = 0; i < v[k].size(); i++)
        {
            if (d[k] + v[k][i].z < d[v[k][i].y])
            {
                d[v[k][i].y] = d[k] + v[k][i].z;
                if (!visit[v[k][i].y])
                {
                    visit[v[k][i].y] = true;
                    q.push(v[k][i].y);
                }
            }
        }
    }
}
void SPFA2(int VV)
{
    int i, j, n, k;
    for (n = 0; n <= N; n++)
    {
        d[n] = MAX;
        visit[n] = false;
    }
    d[VV] = 0;
    visit[VV] = true;
    queue <int> q;
    q.push(VV);
    while (!q.empty())
    {
        k = q.front();
        visit[k] = false;
        q.pop();
        for (i = 0; i < g[k].size(); i++)
        {
            if (d[k] + 1 < d[g[k][i]])
            {
                d[g[k][i]] = d[k] + 1;
                if (!visit[g[k][i]])
                {
                    visit[g[k][i]] = true;
                    q.push(g[k][i]);
                }
            }
        }
    }
}
void create(int VV)
{
    int i, j;
    for (i = 0; i < top; i++)
        if (d[hotel[i]] <= 600 && d[hotel[i]] > 0)
            g[VV].push_back(hotel[i]);
    if (d[N] <= 600 && d[N] > 0)
        g[VV].push_back(N);
}