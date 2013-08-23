#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define stream istringstream
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define INF (1<<30)
#define PI acos(-1.0)
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define memsp(x) mem(x,MEMSET_HALF_INF)
#define memdp(x) mem(x,-1)
#define memca(x) mem(x,0)
#define eps 1e-9
#define pii pair<int,int>
#define pmp make_pair
#define ft first
#define sd second
#define vi vector<int>
#define vpii vector<pii>
#define si set<int>
#define msi map<string , int >
#define mis map<int , string >
typedef long long i64;
typedef unsigned long long ui64;

#define SDi(x) sf("%d",&x)
#define SDl(x) sf("%lld",&x)
#define SDs(x) sf("%s",x)
#define SD2(x,y) sf("%d%d",&x,&y)
#define SD3(x,y,z) sf("%d%d%d",&x,&y,&z)
#define pf printf
#define sf scanf

using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int d[110][110];

int main()
{

    int tc, cas = 1;
    cin >> tc;
    while (tc--)
    {
        pf("Case %d: ", cas++);
        int n, e;
        SDi(n);
        SDi(e);
        memsp(d);
        rep(i, 100) d[i][i] = 0;
        rep(i, e)
        {
            int u, v;
            SD2(u, v);
            d[u][v] = d[v][u] = 1;
        }
        rep(k, n)
        rep(i, n)
        rep(j, n)
        d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

        int source, destination;
        cin >> source >> destination;
        int mn = d[source][0] + d[destination][0];
        for (int i = 0; i < n; i++)
            mn = max(mn , d[source][i] + d[destination][i] );
        pf("%d\n", mn);
    }
    return 0;
}
