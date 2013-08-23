#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <utility>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <iterator>
#include <bitset>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define CLEAR(t) memset((t), 0, sizeof(t))
typedef long long int64;
typedef long double d64;
#define PI acos(-1.0)
#define INF (1<<30)
#define eps 1e-8
#define pb push_back
#define ppb pop_back
#define bg begin
template< class T > T _abs(T n)
{
    return (n < 0 ? -n : n);
}
template< class T > T sq(T n)
{
    return n * n;
}
template< class T > T _max(T a, T b)
{
    return (!(a < b) ? a : b);
}
template< class T > T _min(T a, T b)
{
    return (a < b ? a : b);
}
template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a % b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
template< class T > bool inside(T a, T b, T c)
{
    return a <= b && b <= c;
}
template< class T > void setmax(T &a, T b)
{
    if (a < b) a = b;
}
template< class T > void setmin(T &a, T b)
{
    if (b < a) a = b;
}
template< class T > T power(T N, T P)
{
    if (P == 0) return 1;
    return (P == 1) ?  N : N * power(N, P - 1);
}

int main()
{
    vector <int> v[110];
    vector<int>  tsort;
    queue<int> q;
    int n, e;
    while (scanf("%d %d", &n, &e) && (n || e))
    {
        int in[110];
        memset(in, 0, sizeof(in));
        REP(i, e)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
            in[y]++;
        }
        FOR(i, 1, n)
        {
            if (in[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node  = q.front();
            q.pop();
            tsort.push_back(node);
            REP(i, v[node].size())
            {
                in[v[node][i]]--;
                if (in[v[node][i]] == 0)
                    q.push(v[node][i]);
            }
        }
        printf("%d", tsort[0]);
        FOR(i, 1, tsort.size() - 1)
        printf(" %d", tsort[i]);
        puts("");
        REP(i, 110) v[i].clear();
        tsort.clear();
    }
    return 0;
}
