#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <limits>
using namespace std;

// const
const double len_before_point_digits = 1E6;
const double epsLen = numeric_limits<double>::epsilon() * len_before_point_digits;
// point
typedef complex<double> point;
#define x real()
#define y imag()
// vector
#define crs(a, b) ( (conj(a) * (b)).y )
#define perpendicular(p) ( point((p).y, -(p).x) )
// line
#define intrN(a, b, p, q) ( crs((p)-(a),(b)-(a)) * (q) - crs((q)-(a),(b)-(a)) * (p) )
#define intrD(a, b, p, q) ( crs((p)-(a),(b)-(a)) - crs((q)-(a),(b)-(a)) )
// I/O
#define plus(x) ((x) > 0 ? " + " : " - ")

int main()
{
    point p[3], v[2][2], c;
    double r;
    cout.precision(3);
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y)
    {
        // perpendicular 1
        v[0][0] = 0.5 * (p[0] + p[1]);
        v[0][1] = perpendicular(p[1] - p[0]) + v[0][0];
        // perpendicular 2
        v[1][0] = 0.5 * (p[1] + p[2]);
        v[1][1] = perpendicular(p[2] - p[1]) + v[1][0];
        // intersect
        c = intrN(v[0][0], v[0][1], v[1][0], v[1][1]) / intrD(v[0][0], v[0][1], v[1][0], v[1][1]);
        r = abs(c - p[0]);
        // out
        double h = c.x, k = c.y;
        cout << fixed << "(x" << plus(-h) << abs(h) << ")^2 + (y" <<
             plus(-k) << abs(k) << ")^2 = " << r << "^2" << endl;
        double a = 2 * c.x, b = 2 * c.y, d = c.x * c.x + c.y * c.y - r * r;
        cout << fixed << "x^2 + y^2" << plus(-a) << abs(a) << "x" <<
             plus(-b) << abs(b) << "y" << plus(d) << abs(d) << " = 0" << endl;
        cout << endl;
    }
    return 0;
}