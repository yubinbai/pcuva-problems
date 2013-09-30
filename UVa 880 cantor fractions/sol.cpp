#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<int, int> mii;
int main()
{
    long long n;
    while (cin >> n)
    {
        n *= 2;
        long long p = sqrt(n);
        if ( p * (p + 1) < n ) p++;
        n /= 2;
        long long d = n - p * (p - 1) / 2;
        printf("%lld/%lld\n", (p + 1 - d), d);
    }
    return 0;
}