#include <iostream>
#include <cmath>

using namespace std;

double f(double A, double B, double x);

int main()
{
    double pi = acos(-1);
    int t;
    cin >> t;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    while (t--)
    {
        double A, B;
        cin >> A >> B;
        double ymax = sqrt(A * A + B * B);
        double xmax, a;
        if (B != 0) a = atan(A / B);
        else
        {
            if (A != 0) a = pi / 2;
            else a = 0;
        }
        xmax = a;
        double y = f(A, B, xmax);
        while (!(y <= ymax + 0.0001 && y >= ymax - 0.0001 && xmax >= 0))
        {
            xmax += pi / 2;
            y = f(A, B, xmax);
        }
        cout << xmax << " " << ymax << endl;
    }
}

double f(double A, double B, double x)
{
    return A * sin(x) + B * cos(x);
}