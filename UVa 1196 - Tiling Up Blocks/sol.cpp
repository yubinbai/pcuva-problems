#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <sstream>
#include <complex>
#include <bitset>
#include <iomanip>
#include <cctype>
#include <limits>
#include <numeric>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
#define FORE(k,a,b) for(int k=(a); k <= (int)(b); ++k)
#define FOR(k,a,b) for(int k=(a); k < (int) (b); ++k)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<uint> uvi;
typedef vector<uvi> uvvi;
typedef vector<vd> vvd;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vii> vvii;
typedef pair<uint, uint> uu;
typedef map<string, int> msi;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FOR_IT(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define contains(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
template<typename T>
ostream &operator<<( ostream &os, const vector<T> &vec )
{
    FOR(i, 0, vec.size())
    {
        os << vec[i] << endl;
    }
    return os;
}
bool compareBlocks( const ii &b1, const ii &b2)
{
    if (b1.first != b2.first)
        return b1.first < b2.first;
    return b1.second < b2.second;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
#endif
    int N;
    while (1 == scanf("%d", &N) && N > 0)
    {
        vii seq(N);
        FOR(n, 0, N)
        {
            scanf("%d%d", &seq[n].first, &seq[n].second );
        }
        sort(all(seq), compareBlocks);
        vi dp(N);
        FOR(i, 0, N)
        {
            dp[i] = 1;
            FOR(j, 0, i)
            {
                if (seq[j].first > seq[i].first || seq[j].second > seq[i].second)
                    continue;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        printf("%d\n", *max_element(all(dp)));
    }
    printf("*\n");
    return 0;
}
