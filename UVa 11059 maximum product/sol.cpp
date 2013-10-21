#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <cctype>
#include <ctime>

using namespace std;

int main()
{
    int n, a[20], kase = 0;
    while (scanf("%d", &n) != EOF)
    {
        long long ret = 0LL, prod = 1LL;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            prod = 1LL;
            for (int j = i; j < n; ++j)
            {
                prod *= a[j];
                ret = max(ret, prod);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++kase, ret);
    }
    return 0;
}