#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
const int dx[4] = { -1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int v[2048][2048];
int q[1 << 22][2];
int main(void)
{
    for (int m, n; scanf("%d", &m) == 1 && m; )
    {
        int d = 4096, nx, ny, t = 0, x, y, z;
        FOR(i, 2001) FOR(j, 2001) v[i][j] = 4096;
        FOR(i, m)
        {
            scanf("%d %d", &x, &y);
            v[x][y] = 0;
            q[t][0] = (x << 12) | y;
            q[t][1] = 0;
            ++t;
        }
        FOR(h, t)
        {
            x = q[h][0] >> 12;
            y = q[h][0] & 0xFFF;
            z = q[h][1];
            if (z > v[x][y]) continue;
            FOR(dir, 4)
            {
                nx = x + dx[dir];
                ny = y + dy[dir];
                if (nx >= 0 && nx <= 2000 && ny >= 0 && ny <= 2000 && v[nx][ny] > z + 1)
                {
                    q[t][0] = (nx << 12) | ny;
                    q[t][1] = v[nx][ny] = z + 1;
                    ++t;
                }
            }
        }
        scanf("%d", &n);
        for (int i = 0, x, y; i < n; ++i)
        {
            scanf("%d %d", &x, &y);
            d = min(d, v[x][y]);
        }
        printf("%d\n", d);
    }
    return 0;
}