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
    long long N;
    while (cin >> N)
    {
        long long k = (N + 1) / 2 ;
        k *= 2 * k;
        cout << 3 * (k - 3) << endl;
    }
    return 0;
}
