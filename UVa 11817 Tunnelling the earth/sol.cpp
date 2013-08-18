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

const double pi = acos(-1.0);
const double R = 6371009;
double angle_3d(double lng1, double lat1, double lng2, double lat2)
{
    double dlng = fabs(lng1 - lng2) * pi / 180;
    while ( dlng >= 2 * pi )
        dlng -= pi * 2;
    if ( dlng > pi )
        dlng = 2 * pi - dlng;
    lat1 *= pi / 180;
    lat2 *= pi / 180;
    return acos(cos(lat1) * cos(lat2) * cos(dlng) + sin(lat1) * sin(lat2));
}

int main()
{
    int ncases;
    double la, lb, wa, wb;

    scanf("%d", &ncases);

    while ( ncases-- )
    {
        scanf("%lf%lf%lf%lf", &la, &wa, &lb, &wb);
        double ang = angle_3d(wa, la, wb, lb);
        double l1 = ang * R;
        //double l2 = R * sqrt(2 - 2 * cos(ang));
        double l2 = R * sin(ang / 2.0) * 2;
        printf("%.0lf\n", l1 - l2);
    }

    return 0;
}
