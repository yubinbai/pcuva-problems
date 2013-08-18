#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>



#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)

using namespace std;

#define MAXX 1001

int first_len, second_len;

int dp[MAXX][MAXX];
char str1[MAXX], str2[MAXX];



int LCS(int i, int j)
{
    if (i == first_len || j == second_len ) return 0;

    int &ret = dp[i][j];
    if ( ret != -1 ) return ret;

    if (str1[i] == str2[j])
    {
        return ret = 1 + LCS(i + 1, j + 1);
    }

    return ret = max(LCS(i + 1, j), LCS(i, j + 1));

}


int main()
{




    while (gets(str1))
    {
        gets(str2);
        first_len = strlen(str1);
        second_len = strlen(str2);

        mem(dp, -1);

        printf("%d\n", LCS(0, 0));





    }

    return 0;
}