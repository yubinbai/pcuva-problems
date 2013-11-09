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
#define N 50000
#define LL long long
inline LL Power(int b, int p)
{
    LL ret = 1;
    for ( int i = 1; i <= p; i++ ) ret *= b;
    return ret;
}
const int dr [] = { -1, -1, 0, 1, 1, 1, 0, -1};
const int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
using namespace std;
int accuVal [5000 + 10];
bool hasRepeated(int p)
{
    bool freq [10 + 5];
    Set (freq, false);
    int mod;
    while ( p )
    {
        mod = p % 10;
        if ( freq [mod] ) return false;
        freq [mod] = true;
        p /= 10;
    }
    return true;
}
void preGenerate()
{
    Set (accuVal, 0);
    for ( int i = 1; i <= 5000; i++ )
    {
        accuVal [i] = accuVal [i - 1] + (hasRepeated (i) ? 1 : 0);
    }
}
int main ()
{
    preGenerate();
    int n, m;
    while ( scanf ("%d %d", &n, &m) != EOF )
    {
        printf ("%d\n", accuVal [m] - accuVal [n - 1]);
    }
    return 0;
}
