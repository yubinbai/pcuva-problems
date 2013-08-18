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
using namespace std;
int l, n;
int c [50 + 3];
int dp [50 + 3] [50 + 3];
int bktk (int s, int e)
{
    if ( s + 1 == e ) return 0;
    if ( dp [s] [e] != -1 )
        return dp [s] [e];
    int cost = 0;
    int minimum = INT_MAX;
    for ( int i = s + 1; i < e; i++ )
    {
        cost = bktk (s, i) + bktk (i, e) + c [e] - c [s];
        if ( cost < minimum ) minimum = cost;
    }
    return dp [s] [e] = minimum;
}
void reset ()
{
    for ( int i = 0; i < 53; i++ )
    {
        for ( int j = 0; j < 53; j++ )
            dp [i] [j] = -1;
    }
}
int main ()
{
    while ( scanf ("%d", &l) && l )
    {
        scanf ("%d", &n);
        for ( int i = 1; i <= n; i++ )
            scanf ("%d", &c [i]);
        c [0] = 0;
        c [n + 1] = l;
        reset ();
        printf ("The minimum cutting is %d.\n", bktk (0, n + 1));
    }
    return 0;
}
