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
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;
int R, C;
int matrix [100 + 3] [100 + 3];
int dp [100 + 3] [100 + 3];
void reset ()
{
    memset (dp, -1, sizeof (dp));
}
int backtrack (int x, int y)
{
    if ( dp [x] [y] != -1 ) return dp [x] [y];
    int up = 0, down = 0, right = 0, left = 0;
    if ( x != 0 && matrix [x - 1] [y] < matrix [x] [y] )
        up = backtrack (x - 1, y) + 1;
    if ( x != R - 1 && matrix [x + 1] [y] < matrix [x] [y] )
        down = backtrack (x + 1, y) + 1;
    if ( y != 0 && matrix [x] [y - 1] < matrix [x] [y] )
        left = backtrack (x, y - 1) + 1;
    if ( y != C - 1 && matrix [x] [y + 1] < matrix [x] [y] )
        right = backtrack (x, y + 1) + 1;
    return dp [x] [y] = max (up, max (down, max (right, left)));
}
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    while ( testCase-- )
    {
        reset ();
        char name [100];
        scanf ("%s %d %d", name, &R, &C);
        for ( int i = 0; i < R; i++ )
        {
            for ( int j = 0; j < C; j++ )
                scanf ("%d", &matrix [i] [j]);
        }
        int maxLen = INT_MIN;
        for ( int i = 0; i < R; i++ )
        {
            for ( int j = 0; j < C; j++ )
            {
                int len = backtrack (i, j);
                if ( len > maxLen ) maxLen = len;
            }
        }
        printf ("%s: %d\n", name, maxLen + 1);
    }
    return 0;
}