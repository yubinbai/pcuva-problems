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
    int tc;
    long long n;
    long long k;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        k = sqrt(2 * n);
        cout << ( (k * (k + 1) / 2 > n) ? k - 1 : k) << endl;
    }
    return 0;
}