#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXN 20
using namespace std;
int n, order[MAXN];
double arr[MAXN], minVal;
bool vis[MAXN];
struct Point
{
    double x, y;
};
Point coord[MAXN]; // 保存各个圆心在坐标上的位置
inline double getDist(Point &a, Point &b)
{
    return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline void addCircle(int cur, int pos)
{
    for (int i = 0; i < cur; ++i)
    {
        double l;
        if (coord[i].y != arr[pos])
        {
            double h = fabs( coord[i].y - arr[pos] ); // 高
            double x = coord[i].y + arr[pos]; // 斜线
            l = pow( x * x - h * h, 0.5);
        }
        else
            l = 2 * arr[pos];
        Point temp;
        temp.x = coord[i].x + l,  temp.y = arr[pos];
        if (temp.x <= coord[cur - 1].x) continue;
        // 判断这种放置是否可以
        bool flag = true;
        for (int j = 0; j < cur; ++j)
        {
            if (i == j) continue;
            double t = getDist(coord[j], temp);
            if ( t < coord[j].y + arr[pos])
            {
                flag = false; break;
            }
        }
        if (flag)
        {
            if (temp.x < arr[pos]) // 如果这个圆非常非常大，那么会覆盖掉前面的所有圆
            {
                temp.x = arr[pos];
            }
            coord[cur] = temp;
            return;
        }
    }
}
void search(int cur, double len)
{
    if (cur == n && len < minVal)
    {
        minVal = len;
        return;
    }
    for (int i = 0; i < n; ++i)if (!vis[i])
        {
            vis[i] = true;
            if (cur == 0)
            {
                coord[0].x = arr[i], coord[0].y = arr[i];
            }
            else
            {
                addCircle(cur, i);
            }
            // 新的长度
            double newLen;
            if (coord[cur].x + arr[i] > len) newLen = coord[cur].x + arr[i];
            else newLen = len;
            search(cur + 1, newLen);
            vis[i] = false;
        }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lf", &arr[i]);
        minVal = 2147483646; // 注意！一定要赋值一个足够的的数！开始就是因为没有
        // 给一个足够大的数而WA了很多次而发现不出原因
        memset(vis, 0, sizeof(vis));
        search(0, 0);
        printf("%.3lf\n", minVal);
    }
    return 0;
}