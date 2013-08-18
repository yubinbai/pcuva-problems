#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

int const INF = 0x3f3f3f3f;
#define MAX 10005

int coins[101];
int nCoins[MAX + 1];

int main()
{
    int cases; scanf("%d", &cases);
    while (cases--)
    {
        int target, n; scanf("%d%d", &target, &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &coins[i]);
        for (int i = 0; i <= MAX; ++i) nCoins[i] = INF;
        nCoins[0] = 0;
        int res = INF;
        for (int i = 0; i < n; ++i)
            for (int val = MAX; val >= 0; --val)
                if (nCoins[val] != INF && val + coins[i] <= MAX)
                {
                    if (nCoins[val + coins[i]] > nCoins[val] + 1)
                    {
                        nCoins[val + coins[i]] = nCoins[val] + 1;
                        if (val + coins[i] < res && val + coins[i] >= target && nCoins[val + coins[i]] != INF)
                            res = val + coins[i];
                    }
                }
        cout << res << " " << nCoins[res] << endl;
    }
    return 0;
}