#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<pair<int, int> > vii;
float d, cap, mpg, icost, sd[54], p[54], fuel, ans;
int n;
void rcr(int i)
{
    float tfuel = fuel, tcost = icost;
    fuel -= (sd[i] - sd[i - 1]) / mpg;
    if (fuel > 0)
    {
        if (i == n + 1)
        {
            if (icost < ans) ans = icost;
            fuel = tfuel;
            icost = tcost;
            return;
        }
        rcr(i + 1);
        icost += floor(p[i] * (cap - fuel) + 0.5) + 200;
        fuel = cap;
        if (icost < ans)
            rcr(i + 1);
    }
    fuel = tfuel;
    icost = tcost;
}
int main()
{
    int t = 1;
    while (cin >> d && d >= 0)
    {
        cin >> cap >> mpg >> icost >> n;
        for (int i = 1; i <= n; i++) cin >> sd[i] >> p[i];
        sd[n + 1] = d;
        p[n + 1] = sd[0] = 0;
        fuel = cap;
        ans = 999999999;
        icost *= 100;
        rcr(1);
        printf("Data Set #%d\nminimum cost = $%.2f\n", t++, ans / 100);
    }
    return 0;
}