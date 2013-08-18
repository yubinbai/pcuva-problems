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

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)

using namespace std;

int h, w;
char board [50 + 5] [50 + 5];
int cnt;
int dr [] = { -1, 0, 1, 0 };
int dc [] = {0, 1, 0, -1};

void dfs1 (int x, int y)
{
    if ( x < 0 || x == h || y < 0 || y == w || board [x] [y] != 'X' ) return;

    board [x] [y] = '*';

    for ( int i = 0; i < 4; i++ )
    {
        dfs1 (x + dr [i], y + dc [i]);
    }
}

void dfs (int x, int y)
{
    if ( x < 0 || x == h || y < 0 || y == w || board [x] [y] == '.' ) return;

    if ( board [x] [y] == 'X' )
    {
        cnt++;
        dfs1 (x, y);
    }

    board [x] [y] = '.';

    for ( int i = 0; i < 4; i++ )
    {
        dfs (x + dr [i], y + dc [i]);
    }

}

int main(int argc, char **argv)
{
    int cases = 0;

    while ( scanf ("%d %d", &w, &h) )
    {
        if ( w == 0 && h == 0 ) break;

        for ( int i = 0; i < h; i++ ) scanf ("%s", board [i]);

        vector <int> output;

        for ( int i = 0; i < h; i++ )
        {
            for ( int j = 0; j < w; j++ )
            {
                if ( board [i] [j] != '.' )
                {
                    cnt = 0;
                    dfs (i, j);
                    output.push_back(cnt);
                }
            }
        }

        sort (output.begin(), output.end());

        printf ("Throw %d\n", ++cases);
        printf ("%d", output [0]);
        for ( size_t i = 1; i < output.size(); i++ ) printf (" %d", output [i]);
        printf ("\n\n");
    }

    return 0;
}