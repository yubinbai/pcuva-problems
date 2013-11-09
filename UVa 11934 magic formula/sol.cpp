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
#include <complex>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <ctime>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
#define PI acos(-1.0)
#define EPS 1e-9
#define INF 1<<30
#define FOI(I, A, B) for (I=A; I<=B; I++)
#define FOD(I, A, B) for (I=A; I>=B; I--)
int64 calc(int64 a, int64 b, int64 c, int64 x)
{
    return a * x * x + b * x + c;
}
int main()
{
    while ( true )
    {
        int64 a, b, c, d, L;
        scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &L);
        if ( a == 0 && b == 0 && c == 0 && d == 0 && L == 0 )
            break;
        int64 i, cnt = 0;
        FOI(i, 0, L)
        if ( calc(a, b, c, i) % d == 0 )
            cnt++;
        printf("%lld\n", cnt);
    }
    return 0;
}