#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 110;
struct point
{
    double x, y;
};
struct circle
{
    point p;
    double r;
};
circle c[MAX];
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
double disp2p(point a, point b)
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
int sum, mmax;
bool flag[MAX];
void DFS(int i, int n)
{
    if ( sum > mmax )    mmax = sum;
    for (int k = 0; k < n; k++)
    {
        if ( flag[k] ) continue;
        double len = disp2p(c[i].p, c[k].p);
        if ( xyd(len, c[i].r + c[k].r) && dyd(len + min(c[i].r, c[k].r), max(c[i].r, c[k].r)) )
        {
            sum++;
            flag[k] = 1;
            DFS(k, n);
        }
    }
}
int main()
{
    int n;
    while ( ~scanf("%d", &n) && n != -1 )
    {
        if ( n == 0 )
        {
            printf("The largest component contains 0 rings.\n");
            continue;
        }
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &c[i].p.x, &c[i].p.y, &c[i].r);
        mmax = 0;
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < n; i++)
            if ( !flag[i] )
            {
                sum = 1; flag[i] = 1;
                DFS(i, n);
            }
        if ( mmax > 1 )
            printf("The largest component contains %d rings.\n", mmax);
        else
            printf("The largest component contains 1 ring.\n");
    }
    return 0;
}
