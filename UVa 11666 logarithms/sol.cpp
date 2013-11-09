#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#define INFINITO 0x3f3f3f3f
using namespace std;
int main (void)
{
    double n;
    while (1)
    {
        scanf("%lf", &n);
        if (!n)
            break;
        for (double l = 0.0; ; l += 1.0)
        {
            double x = 1.0 - exp( log(n) - l );
            if (-1.0 < x and x < 1.0)
            {
                printf("%d %.8f\n", int(l), x);
                break;
            }
        }
    }
    return 0;
}