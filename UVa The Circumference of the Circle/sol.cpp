#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const long double PI = 3.141592653589793;

int main()
{
    ios::sync_with_stdio(false);
    long double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
        long double a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        long double b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        long double c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));

        long double area = sqrt((a + b + c) * (b + c - a) * (a - b + c) * (a + b - c) / 16);

        long double d = (a * b * c) / area / 2;

        long double P = PI * d;

        cout << fixed << setprecision(2) << P << endl;
    }
    return 0;
}