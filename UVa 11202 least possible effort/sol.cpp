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
    int m, n;
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> m >> n;
        int nh = (n + 1) / 2;
        int res;
        if (m == n)
        {
            res = nh * (nh + 1) / 2;
        }
        else
        {
            res = nh * ((m + 1) / 2);
        }
        cout << res << endl;
    }
    return 0;
}