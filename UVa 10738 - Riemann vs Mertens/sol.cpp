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
const int MAXP = 1000000;
const int SQRP = 1000; //sqrt(MAX)
int _c[(MAXP >> 6) + 1];
IV primes;
IIV opt;
int Case, mu[1000010], M[1000010];

void prime_sieve ( )
{
    for ( int i = 3; i <= SQRP; i += 2 )
        if ( !IsComp ( i ) ) for ( int j = i * i; j <= MAXP; j += i + i ) SetComp ( j );
    primes.push_back ( 2 );
    for ( int i = 3; i <= MAXP; i += 2 ) if ( !IsComp ( i ) ) primes.push_back ( i );
}

void prime_factorize ( int n, IIV &f )
{
    f.clear();
    int sn = sqrt ( n );
    For ( IV, it, primes )
    {
        int prime = *it;
        if ( prime * prime > n ) break;
        if ( n % prime ) continue;
        int e = 0; for ( ; n % prime == 0; e++, n /= prime ) ;
        f.push_back ( II ( prime, e ) );
    }
    if ( n > 1 ) f.push_back ( II ( n, 1 ) );
}

void init()
{
    mu[1] = M[1] = 1;
    for ( int i = 2; i <= 1000000; ++i )
    {
        prime_factorize ( i, opt );
        bool flag = 1;
        For ( IIV, it, opt )
        {
            if ( it -> second != 1 )
            {
                flag = 0;
                break;
            }
        }
        if ( flag )
        {
            int tmp = opt.size();
            if ( tmp % 2 == 0 ) mu[i] = 1;
            else mu[i] = -1;
        }
        else mu[i] = 0;
        M[i] = M[i - 1] + mu[i];
    }
}

int main ( )
{
    prime_sieve();
    init();
    while ( scanf ( "%d", &Case ) == 1 && Case )
    {
        printf ( "%8d%8d%8d\n", Case, mu[Case], M[Case] );
    }
    return 0;
}