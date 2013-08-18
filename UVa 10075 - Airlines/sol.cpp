#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#define PI 3.141592653589793/180
#define INF 100000000
#define R 6378.0
#define MX 105
using namespace std;

struct City
{
    double lat, lon;
} CL[MX];

map< string, int >MP;
int W[MX][MX];
void Floyed(int);
int MIN(int, int);

int main()
{
    int n, m, q, i, j, k = 1, x, y, f = 1;
    double dis, lat1, lon1, lat2, lon2, cs;
    string cname, src, dst;
    //freopen("in.txt","r",stdin);

    while (scanf("%d%d%d\n", &n, &m, &q) && (n | m | q))
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                W[i][j] = INF;

        for (i = 0; i < n; i++)
        {
            cin >> cname;
            scanf("%lf%lf", &lat1, &lon1);

            MP[cname] = i;
            CL[i].lat = lat1;
            CL[i].lon = lon1;
            W[i][i] = 0;
        }


        for (i = 0; i < m; i++)
        {
            cin >> src >> dst;

            x = MP[src];
            y = MP[dst];

            lat1 = PI * CL[x].lat, lat2 = PI * CL[y].lat;
            lon1 = PI * CL[x].lon, lon2 = PI * CL[y].lon;
            cs = cos(lat1) * cos(lat2) * cos(lon2 - lon1) + sin(lat1) * sin(lat2);
            dis = R * acos( cs );

            //W[x][y] = W[y][x] = dis;
            W[x][y] = int(dis + 0.5);
        }
        Floyed(n);

        if (f)
        {
            printf("Case #%d\n", k++);
            f = 0;
        }
        else
            printf("\nCase #%d\n", k++);

        for (i = 0; i < q; i++)
        {
            cin >> src >> dst;
            x = MP[src];
            y = MP[dst];

            if (W[x][y] == INF)
                printf("no route exists\n");
            else
                printf("%d km\n", W[x][y]);
        }
        MP.clear();
    }
    return 0;
}

void Floyed(int n)
{
    int i, j, k;

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                W[i][j] = MIN(W[i][j], W[i][k] + W[k][j]);
}

int MIN(int x, int y)
{
    return (x < y) ? x : y;
}
