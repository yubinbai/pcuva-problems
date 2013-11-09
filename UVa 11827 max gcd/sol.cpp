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
int64 gcd(int64 a, int64 b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main()
{
    int test;
    scanf("%d\n", &test);
    while (test--)
    {
        int64 n = 0, i = 0, j = 0, z = 34;
        int64 num[100] = {0};
        string str;
        getline(cin, str);
        int64 temp = 0, len = str.length();
        while (i < len)
        {
            if (isdigit(str[i]))
                temp = temp * 10 + (int)(str[i] - '0');
            else
            {
                if (temp > 0)
                {
                    num[n++] = temp;
                    temp = 0;
                }
            }
            i++;
        }
        if (temp != 0)
            num[n++] = temp;
        if (n == 1)
        {
            cout << num[n - 1] << endl;
            continue;
        }
        sort(num, num + n);
        int64 ggcd = 1;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                int64 lgcd = gcd(num[j], num[i]);
                ggcd = (ggcd >= lgcd) ? ggcd : lgcd;
            }
        }
        cout << ggcd << endl;
    }
    return 0;
}