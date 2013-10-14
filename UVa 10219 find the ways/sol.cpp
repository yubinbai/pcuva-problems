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
typedef pair<int, int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int, int>    mii;
map<int, map<int, int> >  mm;
int getC(int n, int m)
{
    if ( n < m)  return 0;
    if (m == n || m == 0)    return 1;
    if (m == 1 || m == n - 1)  return n;
    if (mm.count(n))
    {
        if (mm[n].count(m))   return mm[n][m];
    }
    else mm[n] == map<int, int>();
    return mm[n][m] = getC(n - 1, m - 1) + getC(n - 1, m);
}
int main()
{
    long long n, k;
    while (cin >> n >> k)
    {
        double digit = 0;
        if (k > n - k)
        {
            for (long long i = k + 1; i <= n; i++)
            {
                digit += (log10(i) - log10(n - i + 1));
            }
        }
        else
        {
            for (long long i = n - k + 1; i <= n; i++)
            {
                digit += (log10(i) - log10(n - i + 1));
            }
        }
        digit = floor(digit) + 1;
        printf("%0.lf\n", digit);
    }
    return 0;
}