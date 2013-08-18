#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int LL;

struct Point
{
    LL x, y;
    Point(LL p = 0, LL q = 0)
    {
        x = p;
        y = q;
    }
};
struct Line
{
    Point a, b;
    Line(Point x, Point y)
    {
        a = x;
        b = y;
    }
};
vector<Line> Seg;
double ansX, ansY;

void Input()
{
    Seg.clear();
    LL ax1, ay1, bx1, by1, ax2, ay2, bx2, by2;
    cin >> ax1 >> ay1 >> bx1 >> by1 >> ax2 >> ay2 >> bx2 >> by2;
    Point s1(ax1, ay1), e1(bx1, by1), s2(ax2, ay2), e2(bx2, by2);
    Seg.push_back(Line(s1, e1));
    Seg.push_back(Line(s2, e2));
}

double Direction(Point Pi, Point Pj, Point Pk)
{
    return (Pj.x - Pi.x) * (Pk.y - Pi.y) - (Pk.x - Pi.x) * (Pj.y - Pi.y);
}
//判断向量p q平行（包含共线情况）
bool isParallel(Line p, Line q)
{
    if ( !((p.b.x - p.a.x) * (q.b.y - q.a.y) - (q.b.x - q.a.x) * (p.b.y - p.a.y)) )
        return true;
    return false;
}
//判断线段p,q是否相交
int isIntersect(Line p, Line q)
{
    LL d1, d2, d3, d4;
    d1 = Direction(p.a, p.b, q.a);
    d2 = Direction(p.a, p.b, q.b);
    d3 = Direction(q.a, q.b, p.a);
    d4 = Direction(q.a, q.b, p.b);
    if (isParallel(p, q))
    {
        if (((!d1 && !d2) || (!d3 && !d4))) //重叠
        {
            return 2;
        }
        else return 3;  //平行不共线
    }
    //相交
    else
    {
        ansX = (double)(q.a.x * d2 - q.b.x * d1) / (d2 - d1);
        ansY = (double)(q.a.y * d2 - q.b.y * d1) / (d2 - d1);
        return 1;
    }
}

void Compute()
{
    int ff;
    ff = isIntersect(Seg[0], Seg[1]);
    if (ff == 1) //相交 输出交点
        printf("POINT %.2lf %.2lf\n", ansX, ansY);
    if (ff == 2)
        cout << "LINE" << endl; //重叠
    if (ff == 3)
        cout << "NONE" << endl; //平行
}

int main()
{
    int testCase;
    while (cin >> testCase)
    {
        cout << "INTERSECTING LINES OUTPUT" << endl;
        while (testCase--)
        {
            Input();
            Compute();
        }
        cout << "END OF OUTPUT" << endl;
    }
    return 0;
}