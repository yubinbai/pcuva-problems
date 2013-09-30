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
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
using namespace std;
int main()
{
    vector <int64> vec;
    vector <int64>::iterator it;
    int64 num, val;
    while (cin >> num)
    {
        vec.push_back(num);
        sort(vec.begin(), vec.end());
        int len = (int) vec.size();
        int cen = (int) len / 2;
        if (len % 2 == 0)
            val = ( vec[cen] + vec[cen - 1] ) / 2;
        else
            val = vec[cen];
        cout << val << endl;
    }
    return 0;
}