#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define min(a,b) (a<b)?a:b
int n;
int maxV;
int dp[11][1025];
typedef struct p
{
    int x, y;
} point;
int distance(point *a, point *b)
{
    return abs(a->x - b->x) + abs(a->y - b->y);
}
point nodes[11];
int tsp(int current, int vis)
{
    if (vis == maxV)
        return dp[current][vis] = distance(nodes + current, nodes);
    else if (dp[current][vis] != -1)
        return dp[current][vis];
    else
    {
        int m = 1 << 30;
        int i;
        for (i = 1; i < n; i++)
            if (!((1 << i)&vis))
                m = min(m, distance(nodes + current, nodes + i) + tsp(i, vis | (1 << i)));
        return dp[current][vis] = m;
    }
}
int main()
{
    int c, j, i;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d %d", &i, &i);
        scanf("%d %d", &nodes[0].x, &nodes[0].y);
        scanf("%d", &n);
        n++;
        for (i = 1; i < n; i++)
            scanf("%d %d", &nodes[i].x, &nodes[i].y);
        maxV = (1 << n) - 1;
        for (i = 0; i < n; i++)
            for (j = 0; j <= maxV; j++)
                dp[i][j] = -1;
        printf("The shortest path has length %d\n", tsp(0, 1));
    }
    return 0;
}