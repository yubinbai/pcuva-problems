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
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++)
    {
        int N, K, P;
        cin >> N >> K >> P;
        int val = (K + P) % N;
        if (val == 0)
            val = N;
        cout << "Case " << t << ": " << val << endl;
    }
    return 0;
}