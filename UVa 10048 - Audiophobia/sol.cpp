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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;
int d [100 + 5] [100 + 5];
void reset (int c)
{
    for ( int i = 0; i <= c; i++ )
    {
        for ( int j = 0; j <= c; j++ )
            d [i] [j] = INT_MAX;
    }
}
int main ()
{
    int c, s, q;
    int cases = 0;
    bool blank = false;
    while ( scanf ("%d %d %d", &c, &s, &q) )
    {
        if ( c == 0 && s == 0 && q == 0 ) break;
        reset (c);
        int c1, c2, deci;
        for ( int i = 0; i < s; i++ )
        {
            scanf ("%d %d %d", &c1, &c2, &deci);
            d [c1] [c2] = d [c2] [c1] = deci;
        }
        for ( int k = 1; k <= c; k++ )
        {
            for ( int i = 1; i <= c; i++ )
            {
                for ( int j = 1; j <= c; j++ )
                    d [i] [j] = d [j] [i] = min (d [i] [j], max (d [i] [k], d [k] [j]));
            }
        }
        if ( blank ) printf ("\n");
        blank = true;
        printf ("Case #%d\n", ++cases);
        for ( int i = 0; i < q; i++ )
        {
            scanf ("%d %d", &c1, &c2);
            if ( d [c1] [c2] == INT_MAX ) printf ("no path\n");
            else printf ("%d\n", d [c1] [c2]);
        }
    }
    return 0;
}