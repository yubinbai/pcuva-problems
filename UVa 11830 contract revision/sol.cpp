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
        int i = 0;
        char ch, str[110];
        cin >> ch >> str;
        if (ch == '0' && strlen(str) == 1 && str[0] == '0')
            break;
        int len = strlen(str);
        for (i = 0; i < len; i++)
        {
            if (str[i] == ch)
                str[i] = 'q';
        }
        string ans = "";
        i = 0;
        while (str[i] == '0' || str[i] == 'q')
        {
            i++;
            if (i >= len)
                break;
        }
        for ( ; i < len; i++)
            if (str[i] != 'q')
                ans += str[i];
        if (ans.length() == 0)
            cout << "0\n";
        else
            cout << ans << endl;
    }
    return 0;
}