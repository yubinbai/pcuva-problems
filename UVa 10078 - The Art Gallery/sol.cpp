#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
using namespace std;

typedef long double gtype;
const gtype pi = M_PI;
typedef complex<gtype> point;
#define x real()
#define y imag()
#define crs(a, b) ( (conj(a) * (b)).y )

bool polIsConvex(vector<point> &p)
{
    int a[2] = { 0, 0 }, n = p.size() - 1;
    for (size_t i = 1; i < p.size(); ++i)
    {
        long double cross = crs(p[i % n] - p[i - 1], p[(i + 1) % n] - p[i - 1]);
        if (cross != 0)
            ++a[cross > 0];
    }
    return !(a[0] && a[1]);
}

int main()
{
    char answer[2][4] = { "Yes", "No" };
    int n;
    while (cin >> n && n)
    {
        // polygons
        vector<point> p(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        p[n] = p[0];
        // is convex
        cout << answer[polIsConvex(p)] << endl;
    }
    return 0;
}