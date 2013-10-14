#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define  MAXN  0XFFFFFFF/*无穷大的数*/
#define  N 100010

struct Point
{
    double x;
    double y;
} p[N];
int n;
int tmp_p[N];/*存储中线两边距离为d区间内点的下标*/

/*对点进行按照x坐标排序*/
bool cmpx(Point a , Point b)
{
    if (a.x < b.x) return true;
    return false;
}

/*对点进行按照y坐标排序*/
bool cmpy(int a, int b)
{
    if (p[a].y < p[b].y) return true;
    return false;
}

/*最小值函数*/
double min(double a, double b)
{
    return a < b ? a : b;
}

/*求出两个点之间的距离*/
double dis(int i, int j)
{
    double tmp_x = (p[i].x - p[j].x) * (p[i].x - p[j].x);
    double tmp_y = (p[i].y - p[j].y) * (p[i].y - p[j].y);
    return sqrt(tmp_x + tmp_y);
}

/*递归求解*/
double Closest_Pair(int left, int right)
{
    int i, j, k = 0;
    double d = MAXN;/*d必须为局部变量*/
    if (left == right) return d;/*相等的时候不再递归*/
    if (left + 1 == right) return dis(left, right);/*两个点之间相邻直接计算*/
    int mid = (left + right) >> 1;/*求出两个中点的坐标,位运算*/
    double d1 = Closest_Pair(left, mid);/*左边递归求解*/
    double d2 = Closest_Pair(mid + 1, right); /*右边递归求解*/
    d = min(d1, d2);/*更新d*/
    /*每次同时更新中线两边距离为d的区间上的点*/
    for (i = left; i <= right; i++)
    {
        if (fabs(p[mid].x - p[i].x) <= d)/*两者之间的横坐标距离差绝对值小于等于d*/
            tmp_p[k++] = i;/*插入数组后面*/
    }
    sort(tmp_p, tmp_p + k, cmpy);/*按照y坐标排序*/
    /*扫描这些点更新d值*/
    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < k && p[tmp_p[j]].y - p[tmp_p[i]].y < d ; j++) /*只需要枚举差值小于d的即可*/
        {
            double d3 = dis(tmp_p[i], tmp_p[j]);
            if (d - d3 > 1e-9) d = d3; /*判断能否更新d*/
        }
    }
    return d;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    double MIN;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmpx);/*排序*/
        MIN = Closest_Pair(0, n - 1); /*求出最小值MIN*/
        if (MIN - 10000 > 1e-9) printf("INFINITY\n");
        else printf("%.4lf\n", MIN);
    }
    return 0;
}