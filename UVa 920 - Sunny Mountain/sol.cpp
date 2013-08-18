#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG puts("here!!!")
#define STOP system("pause")

using namespace std;

const int MAX = 110;
struct point
{
    double x, y;
    bool peak;
};
point p[MAX];
const double eps = 1e-6;
bool dy(double x, double y)
{
    return x > y + eps;   // x > y
}
bool xy(double x, double y)
{
    return x < y - eps;   // x < y
}
bool dyd(double x, double y)
{
    return x > y - eps;   // x >= y
}
bool xyd(double x, double y)
{
    return x < y + eps;   // x <= y
}
bool dd(double x, double y)
{
    return fabs( x - y ) < eps;   // x == y
}
double disp2p(point a, point b) //  a b 两点之间的距离
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
bool cmp(point a, point b)
{
    return a.x < b.x;
}
point l2l_inst_p(point u1, point u2, point v1, point v2)
{
    point ans = u1;
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
               ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    ans.x += (u2.x - u1.x) * t;
    ans.y += (u2.y - u1.y) * t;
    return ans;
}
int main()
{
    int ncases, n;

    scanf("%d", &ncases);

    while ( ncases-- )
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
            p[i].peak = false;
        }

        sort(p, p + n, cmp);

        int i = 0;
        if ( p[0].y < p[1].y )      //如果第一个点是山谷，那么第二个点一定是山顶
            i = 1;
        for (; i < n; i += 2)
            p[i].peak = true; //标记山顶的点

        double len = 0.0;

        for (int i = 0; i < n; i++)
        {
            if ( p[i].peak )
            {
                double high = 0.0;
                for (int k = i + 2; k < n; k++)
                    if ( dy(p[k].y, high) )
                        high = p[k].y;
                if ( dyd( high, p[i].y) )
                    continue;

                point t; t.x = -1; t.y = high;
                point tt = t; tt.x = -2;
                point c = l2l_inst_p(tt, t, p[i], p[i + 1]);
                len += disp2p(c, p[i]);
            }
        }

        printf("%.2lf\n", len);
    }

    return 0;
}
