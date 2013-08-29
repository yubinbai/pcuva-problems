#include <cstring>
#include <cmath>
#include <cstdio>
#include <cfloat>
using namespace std;

int main()
{
    int tree[5000 + 5][3], N = 0;
    int dist[10];
    memset(dist, 0, sizeof dist);

    while (true)
    {
        scanf("%d%d%d", &tree[N][0], &tree[N][1], &tree[N][2]);
        if (!(tree[N][0] || tree[N][1] || tree[N][2])) break;
        ++N;
    }

    for (int i = 0; i < N; i++)
    {
        double minD = DBL_MAX;
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;
            double xD = tree[i][0] - tree[j][0];
            double yD = tree[i][1] - tree[j][1];
            double zD = tree[i][2] - tree[j][2];
            double DD = sqrt(xD * xD + yD * yD + zD * zD);
            if (DD < minD) minD = DD;
        }
        if (minD < 10) ++dist[(int) minD];
    }

    for (int i = 0; i < 10; i++) printf("%4d", dist[i]);
    printf("\n");
    return 0;
}