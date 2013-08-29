#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "stdlib.h"
#include "stdio.h"
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int a, b, c, d, n, test = 1;
    string s;
    scanf("%d", &n);
    getline(cin, s, '\n');
    while (test <= n)
    {
        if (test != 1)
            getline(cin, s, '\n');
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
        a = max(x1, x3);
        b = max(y1, y3);
        c = min(x2, x4);
        d = min(y2, y4);
        if (a >= c || b >= d)
        {
            cout << "No Overlap" << endl;
        }
        else
        {
            cout << a << " " << b << " " << c << " " << d << endl;
        }
        if (test != n)
        {
            cout << endl;
        }
        test++;
    }
}