#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x, y;
    point(double p = 0, double q = 0)
    {
        x = p;
        y = q;
    }
};
struct line
{
    point a, b;
    line(point x, point y)
    {
        a = x;
        b = y;
        nn = 0;
    }
    int nn;
};
int segNum;
vector <line> Seg;

void Input()
{
    Seg.clear();
    double ax, ay, bx, by;
    cin >> segNum;
    for (int i = 0; i < segNum; i++)
    {
        cin >> ax >> ay >> bx >> by;
        point start(ax, ay), end(bx, by);
        Seg.push_back(line(start, end));
    }
}

double Direction(point Pi, point Pj, point Pk)
{
    return (Pj.x - Pi.x) * (Pk.y - Pi.y) - (Pk.x - Pi.x) * (Pj.y - Pi.y);
}

bool isIntersect(line p, line q)
{
    double d1, d2, d3, d4;
    d1 = Direction(p.a, p.b, q.a);
    d2 = Direction(p.a, p.b, q.b);
    d3 = Direction(q.a, q.b, p.a);
    d4 = Direction(q.a, q.b, p.b);
    if (d1 * d2 < 0 && d3 * d4 < 0)
    {
        return true;
    }

    else return false;
}

void Compute()
{
    int newSegNum = 0;
    for (int i = 0; i < segNum; i++)
    {
        for (int k = i + 1; k < segNum; k++)
            if (isIntersect(Seg[i], Seg[k]))
                Seg[i].nn += 2;
        newSegNum += (Seg[i].nn + 1);
    }
    cout << newSegNum << endl;
}

int main()
{
    int testCase;
    while (cin >> testCase)
    {
        getchar();
        getchar();
        for (int i = 0; i < testCase; i++)
        {
            if (i > 0) cout << endl;
            Input();
            Compute();
        }
    }
    return 0;
}