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
long long tbl[78];
int main()
{
    tbl[0] = 1; tbl[1] = 1; tbl[2] = 2;
    for (int i = 3; i < 78; i++)
    {
        tbl[i] = tbl[i - 2] + tbl[i - 3];
    }
    int n;
    while (cin >> n)
    {
        cout << tbl[n] << endl;
    }
    return 0;
}