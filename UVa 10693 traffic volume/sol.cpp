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
    int L, f;
    while (cin >> L >> f, L || f)
    {
        double v = sqrt(2 * L * f);
        printf("%.8lf %.8lf\n", v, 1 / (v / (2 * f) + L / v) * 3600);
    }
    return 0;
}