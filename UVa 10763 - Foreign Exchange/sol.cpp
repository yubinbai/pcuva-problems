#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define MAXN 500010
int n , flag;
int loc[MAXN] , res[MAXN];
int solve()
{
    sort(loc , loc + n);
    sort(res , res + n);
    for (int i = 0 ; i < n ; i++)
    {
        if (loc[i] != res[i]) return 0;
    }
    return 1;
}
int main()
{
    while (scanf("%d" , &n) && n)
    {
        for (int i = 0 ; i < n ; i++)
            scanf("%d%d" , &loc[i] , &res[i]);
        flag = solve();
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
