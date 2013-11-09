#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INF 21474836
using namespace std;
int cost[21][21];
int main()
{
    int n, i, j, k, x, y, cn = 0;
    while (scanf("%d", &n) != EOF)
    {
        cn++;
        for (i = 0; i < 21; i++)
            for (j = 0; j < 21; j++)
                cost[i][j] = i == j ? 0 : INF;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            cost[1][x] = 1;
            cost[x][1] = 1;
        }
        for (i = 2; i <= 19; i++)
        {
            scanf("%d", &n);
            for (j = 0; j < n; j++)
            {
                scanf("%d", &x);
                cost[i][x] = 1;
                cost[x][i] = 1;
            }
        }
        for (k = 1; k <= 20; k++)
            for (i = 1; i <= 20; i++)
                for (j = 1; j <= 20; j++)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        scanf("%d", &n);
        printf("Test Set #%d\n", cn);
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            printf("%2d to %2d: %d\n", x, y, cost[x][y]);
        }
        printf("\n");
    }
    return 0;
}