#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long
inline LL Power(int b, int p)
{
    LL ret = 1;
    for ( int i = 1; i <= p; i++ ) ret *= b;
    return ret;
}
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
using namespace std;
int main ()
{
    int testCases; scanf ("%d", &testCases);
    int cases = 0;
    while ( testCases-- )
    {
        char inp [20]; scanf ("%s", inp);
        int len = strlen(inp);
        int a = 0;
        int b = 0;
        char firstStr [10];
        int result = 0;
        printf ("Case %d: ", ++cases);
        sscanf(inp, "%d%s", &a, firstStr);
        bool digitFound = true;
        for ( int i = 0; i < len; i++ )
        {
            if ( isdigit(inp [i]) && digitFound ) continue;
            digitFound = false;
            if ( isdigit(inp [i]) )
            {
                digitFound = true;
                b = inp [i] - '0';
                break;
            }
        }
        result = a * 50;
        result += b * 5;
        printf ("%d", result / 100);
        result %= 100;
        if ( result )
        {
            if ( result % 10 == 0 ) printf (".%d", result / 10);
            else printf (".%d", result);
        }
        printf ("\n");
    }
    return 0;
}
