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
//Commonly used macros
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)           (int)(a.size())
#define ALL(a)          (a).begin(),(a).end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a);(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
//For debugging purpose
#define debug(args...)  {dbg,args; cerr<<endl;}
struct debugger
{
    template <typename T>
    debugger &operator , (const T &v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;
void debugarr(int *a, int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("]\n");
}
//Main code begins here
int main()
{
    int kase, len, maxi, k;
    string s;
    char g[101][101], tmp;
    scanf("%d%c", &kase, &tmp);
    while (kase--)
    {
        getline(cin, s);
        len = SZ(s);
        maxi = 0;
        for (int i = 0; i * i <= len; ++i)
        {
            if (i * i == len)
            {
                maxi = i;
                break;
            }
        }
        if (maxi == 0) printf("INVALID\n");
        else
        {
            k = 0;
            for (int i = 0; i < maxi; ++i)
            {
                for (int j = 0; j < maxi; ++j)
                {
                    g[i][j] = s[k++];
                }
            }
            for (int i = 0; i < maxi; ++i)
            {
                for (int j = 0; j < maxi; ++j)
                {
                    printf("%c", g[j][i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}