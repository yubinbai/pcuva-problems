#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;
#define MAX 15
char table[128];
char grid[MAX][MAX];
bool visited[MAX][MAX];
int x[200], y[200];
int di[] = { -1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
int n, m, s;
int main()
{
    table['N'] = 0, table['S'] = 1, table['W'] = 2, table['E'] = 3;
    while (scanf("%d %d %d", &n, &m, &s) == 3)
    {
        if (!n && !m && !s)break;
        for (int i = 0; i < n; ++i)
            scanf("%s", grid[i]);
        memset(visited, 0, sizeof(visited));
        int cnt = 0, curi = 0, curj = s - 1, inLoop = 0, loopNum = 0;
        visited[curi][curj] = 1;
        while (1)
        {
            int ti = curi, tj = curj;
            curi += di[table[grid[ti][tj]]];
            curj += dj[table[grid[ti][tj]]];
            if (curi >= 0 && curi < n && curj >= 0 && curj < m)
            {
                if (visited[curi][curj])
                {
                    int i;
                    for (i = cnt - 1; i >= 0; --i)
                    {
                        if (x[i] == curi && y[i] == curj)
                            break;
                    }
                    inLoop = 1;
                    loopNum = cnt - i;
                    break;
                }
                else
                {
                    visited[curi][curj] = 1;
                    x[cnt] = curi, y[cnt] = curj;
                    cnt++;
                }
            }
            else break;
        }
        if (inLoop)
        {
            printf("%d step(s) before a loop of %d step(s)\n", cnt - loopNum + 1, loopNum);
        }
        else
        {
            printf("%d step(s) to exit\n", cnt + 1);
        }
    }
    return 0;
}