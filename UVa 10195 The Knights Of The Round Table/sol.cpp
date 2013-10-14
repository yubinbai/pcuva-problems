#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double radious(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c)) / s;
}
int main()
{
    //cout.precision(4);
    double a, b, c, r;
    while (cin >> a >> b >> c)
    {
        if (a > 0 && b > 0 && c > 0)
        {
            r = radious(a, b, c);
            printf("The radius of the round table is: %.3lf\n", r);
        }
        else
        {
            cout << "The radius of the round table is: 0.000" << endl;
        }
    }
    return 0;
}