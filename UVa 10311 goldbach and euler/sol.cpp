#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
using namespace std;
const int INF = 0x7fffffff;
typedef pair<int, int> II;
typedef vector<int> IV;
typedef vector<II> IIV;
typedef vector<bool> BV;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
#define For(t,v,c) for(t::const_iterator v=c.begin(); v!=c.end(); ++v)
#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 100000000;
const int SQRP = 10000; //sqrt(MAX)
int _c[(MAXP >> 6) + 1];
void prime_sieve ( )
{
    for ( int i = 3; i <= SQRP; i += 2 )
        if ( !IsComp ( i ) )
            for ( int j = i * i; j <= MAXP; j += i + i )
                SetComp ( j );
}
bool is_prime ( int n )
{
    if ( n < 2 || ( n > 2 && n % 2 == 0 ) ) return false;
    return !IsComp ( n );
}
int Case;
int main ( )
{
    prime_sieve ( );
    while ( scanf ( "%d", &Case ) == 1 )
    {
        if ( Case % 2 == 0 )
        {
            int left, right;
            bool flag = 0;
            for ( int i = Case / 2; i >= 2; --i )
                if ( is_prime ( i ) && is_prime ( Case - i ) && i != ( Case - i ) )
                {
                    left = i, right = Case - i, flag = 1;
                    break;
                }
            if ( flag ) printf ( "%d is the sum of %d and %d.\n", Case, left, right );
            else printf ( "%d is not the sum of two primes!\n", Case );
        }
        else
        {
            if ( is_prime ( Case - 2 ) ) printf ( "%d is the sum of 2 and %d.\n", Case, Case - 2 );
            else printf ( "%d is not the sum of two primes!\n", Case );
        }
    }
    return 0;
}