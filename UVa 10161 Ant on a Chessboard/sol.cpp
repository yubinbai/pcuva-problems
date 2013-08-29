#include<iostream>
#include<cmath>
#include<cstdlib>
#include "stdio.h"
using namespace std;
int main()
{
    long x, y, t, p;
    long double s;
    while (cin >> t && t)
    {
        s = sqrt(t);
        x = ceil(s);
        y = x - abs(x * (x - 1) - t + 1);
        p = s + 0.5;
        if ((p & 1))
        {
            t = x, x = y, y = t;
        }
        cout << x << " " << y << endl;
    }
    exit(0);
}