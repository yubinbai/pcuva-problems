#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int a, b, cost, n, m, dist[100000], min_dist;
char name[30];
int main()
{
    while ( gets(name) && strlen(name) > 0)
    {
        memset(dist, INF, sizeof(dist));
        scanf("%d %d\n", &n, &m);
        min_dist = INF;
        for (int i = 0; i < m; i++) dist[i] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    scanf("%d", &cost);
                    a = m * (i + 1) + k; b = m * i + j;
                    dist[a] = min(dist[a], dist[b] + cost + 2 );
                    //  printf("dist[%d] = %d\n",(n-1)*(i+1)+k, min( dist[(n-1)*(i+1)+k], dist[(n-1)*i+j] + a + 2 ));
                }
                scanf("\n");
            }
        }
        for (int i = n * m - m; i < n * m ; i++) min_dist = min(min_dist, dist[i]);
        printf("%s\n%d\n", name, min_dist);
    }
    return 0;
}