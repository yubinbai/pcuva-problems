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

const int MAX = 120;
struct point
{
    double x, y;
};
point p[MAX];

double crossProduct(point a, point b, point c) //向量 ac 在 ab 的方向 顺时针是正
{
    return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
bool cmp( point a, point b)
{
    if ( a.x == b.x ) return a.y < b.y;
    return a.x < b.x;
}
bool equal_cmp(point a, point b)
{
    return a.x == b.x && a.y == b.y;
}

int main()
{
    int ncases, n, ind = 1;

    scanf("%d", &ncases);

    while ( ncases-- )
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);

        sort(p, p + n, cmp);
        n = unique(p, p + n, equal_cmp) - p;

        printf("Data set #%d contains ", ind++);
        if ( n == 1 )
        {
            puts("a single gnu.");
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int k = i + 1; k < n; k++)
            {
                int sum = 2;
                for (int l = k + 1; l < n; l++)
                    if ( crossProduct(p[i], p[k], p[l]) == 0 )
                        sum++;
                if ( sum > ans )
                    ans = sum;
            }

        printf("%d gnus, out of which a maximum of %d are aligned.\n", n, ans);
    }

    return 0;
}
