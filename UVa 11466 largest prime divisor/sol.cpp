#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define PI                acos(-1.0)
#define INF                1<<30
#define EPS                1e-9
#define sqr(x)        (x)*(x)
#define MAX                10000050
bool isPrime[MAX + 1];
vector<int64> Prime;
int S = 0;
void seive()
{
    memset(isPrime, true, sizeof isPrime);
    Prime.clear();
    isPrime[0] = false; isPrime[1] = false;
    int i, j;
    FOI(i, 2, MAX)
    {
        if ( isPrime[i] )
        {
            Prime.push_back(i);
            for (j = 2 * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    S = Prime.size() - 1;
}
int main()
{
    seive();
    while ( true )
    {
        int64 N;
        scanf("%lld", &N);
        if ( N == 0 )
            break;
        N = N < 0 ? -N : N;
        int64 cnt = 0, big = 2;
        int i;
        FOI(i, 0, S)
        {
            if ( Prime[i] > N ) break;
            if ( N % Prime[i] == 0 )
            {
                big = max(big, Prime[i]);
                ++cnt;
                while ( N % Prime[i] == 0 )
                {
                    N /= Prime[i];
                }
            }
        }
        if ( N > Prime[S] || isPrime[N] )
        {
            ++cnt;
            big = max(N, big);
        }
        if ( cnt < 2 )
            printf("-1\n");
        else
            printf("%lld\n", big);
    }
    return 0;
}