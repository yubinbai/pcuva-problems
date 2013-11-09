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
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Pr(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) cout << *it << " "; cout << endl;
#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;
bool mark [N];
vector <int> primeList;
int primeFactorCnt [N];
void sieve ()
{
    Set (mark, true);
    mark [0] = mark [1] = false;
    for ( int i = 4; i < N; i += 2 ) mark [i] = false;
    for ( int i = 3; i * i <= N; i += 2 )
        if ( mark [i] ) for ( int j = i * i; j < N; j += 2 * i ) mark [j] = false;
    primeList.push_back (2);
    for ( int i = 3; i < N; i += 2 ) if ( mark [i] ) primeList.push_back (i);
    // printf ("%d\n", primeList.size ());
}
bool calcPrimeFactor (int n, int m)
{
    Set (primeFactorCnt, 0);
    Fs (i, primeList)
    {
        int tmp = n;
        while ( tmp )
        {
            primeFactorCnt [primeList [i]] += tmp / primeList [i];
            tmp /= primeList [i];
        }
    }
    int ind = 0;
    while ( primeList [ind] * primeList [ind] <= m )
    {
        while ( m % primeList [ind] == 0 )
        {
            primeFactorCnt [primeList [ind]]--;
            m /= primeList [ind];
        }
        ind++;
    }
    if ( m > 1 )     // m is a prime
    {
        if ( n < m ) return false;
    }
    for ( size_t i = 0; i < primeList.size (); i++ )
    {
        if ( primeFactorCnt [primeList [i]] < 0 ) return false;
    }
    return true;
}
int main ()
{
    sieve ();
    int n, m;
    while ( scanf ("%d %d", &n, &m) != EOF )
    {
        if ( n >= m )
        {
            printf ("%d divides %d!\n", m, n);
            continue;
        }
        if ( calcPrimeFactor (n, m) ) printf ("%d divides %d!\n", m, n);
        else printf ("%d does not divide %d!\n", m, n);
    }
    return 0;
}
