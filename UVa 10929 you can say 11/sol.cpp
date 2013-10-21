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
    while (true)
    {
        string str;
        cin >> str;
        if (str == "0")
            break;
        int len = str.length(), i;
        int64 sum = 0;
        for (i = 0; i < len; i++)
        {
            if (i % 2 == 0)
                sum += (str[i] - '0');
            else
                sum -= (str[i] - '0');
        }
        if (sum < 0)
            sum *= -1;
        if (sum % 11 == 0)
            cout << str << " is a multiple of 11.\n";
        else
            cout << str << " is not a multiple of 11.\n";
    }
    return 0;
}