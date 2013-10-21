#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define EPS        1e-9
int main()
{
    int T, t;
    cin >> T;
    FOI(t, 1, T)
    {
        printf("Case %d: ", t);
        double D, V, U;
        scanf("%lf%lf%lf", &D, &V, &U);
        bool stat = true;
        if (U <= V || U <= 0 || V <= 0)
            printf("can't determine");
        else
        {
            double theta = asin(V / U);
            double U1 = V / tan(theta);
            double T1 = D / U1;
            double T2 = D / U;
            printf("%.3lf", T1 - T2);
        }
        printf("\n");
    }
    return 0;
}
