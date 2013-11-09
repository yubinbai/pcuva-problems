#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define PI 3.141592653589793
using namespace std;
int main()
{
    for (;;)
    {
        double D, V;
        scanf("%lf%lf", &D, &V);
        if (D == 0 && V == 0)
            break;
        double val = D * D * D - 6 * V / PI;
        double d = pow(val, 1.0 / 3.0);
        printf("%.3lf\n", d);
    }
    return 0;
}