#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int64;
int64 Gcd (int64 a, int64 b)
{
    for (int64 t = a % b; t; a = b, b = t, t = a % b); return b;
}
void ExpandGcd (int64 a, int64 b, int64 &d, int64 &x, int64 &y)
{
    if (b)
    {
        ExpandGcd (b, a % b, d, y, x);
        y -= a / b * x;
    }
    else
    {
        d = a;
        x = 1;
        y = 0;
    }
}
int main ()
{
    int64 n, n1, n2, c1, c2;
    int64 d, x0, y0, x1, y1, x2, y2, ansx, ansy;
    while (cin >> n && n)
    {
        cin >> c1 >> n1 >> c2 >> n2;
        //  Input
        d = Gcd (n1, n2);
        if (n % d)
        {
            printf ("failed\n");
            continue;
        }
        n /= d; n1 /= d; n2 /= d;
        ExpandGcd (n1, n2, d, x0, y0);
        x0 *= n;
        y0 *= n;
        int64 a = (int64)ceil (-(double)x0 / n2), b = (int64)floor ((double)y0 / n1);
        if (a > b)
        {
            printf ("failed\n");
            continue;
        }
        x1 = x0 + n2 * a;
        y1 = y0 - n1 * a;
        x2 = x0 + n2 * b;
        y2 = y0 - n1 * b;
        if (x1 * c1 + y1 * c2 < x2 * c1 + y2 * c2)
        {
            ansx = x1;
            ansy = y1;
        }
        else
        {
            ansx = x2;
            ansy = y2;
        }
        //  Solve
        cout << ansx << " " << ansy << endl;
        //  Output
    }
    return 0;
}