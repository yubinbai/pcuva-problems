#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    double ncow, ncar, nshow;
    while (scanf("%lf%lf%lf", &ncow, &ncar, &nshow) != EOF)
    {
        double val1 = ncar * (ncow + ncar - 1);
        double val2 = (ncow + ncar) * (ncow + ncar - nshow - 1);
        double val = val1 / val2;
        printf("%.5lf\n", val);
    }
    return 0;
}