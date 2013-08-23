#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
#define PI acos(-1)
int main()
{
    int n, t = 0;
    while (1)
    {
        cin >> n;
        if (n < 3) break;
        double areaP;
        cin >> areaP;
        double areaT = areaP / n;
        double cAngle = 2.0 * PI / n;
        double rOut = sqrt(2.0 * areaT / sin(cAngle));
        double tAngle = cAngle / 2;
        double rIn = rOut * cos(tAngle);
        double off = areaP - (PI * rIn * rIn);
        double spec = PI * rOut * rOut - areaP;
        printf("Case %d: %.5f %.5f\n", ++t, spec, off);
    }
    return 0;
}