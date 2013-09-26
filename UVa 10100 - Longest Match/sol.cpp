#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
const int maxn = 1010;
using namespace std;
string s1[maxn], s2[maxn];
char a[maxn], b[maxn], temp[31];
int dp[maxn][maxn];
int alength, blength, count1 = 0;
inline int max(int a, int b)
{
    return a > b ? a : b;
}
void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= alength; i++)
    {
        for (int j = 1; j <= blength; j++)
        {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%2d. Length of longest match: %d\n", ++count1, dp[alength][blength]);
}
void StepOne(char *s)
{
    for (int i = 1; i <= strlen(s + 1); i++)
    {
        if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'));
        else if ( (s[i] >= '0' && s[i] <= '9') );
        else s[i] = ' ';
    }
}
int main()
{
    while (gets(a + 1) != NULL)
    {
        gets(b + 1);
        if ((a[1] == 0) || (b[1] == 0))
        {
            printf("%2d. Blank!\n", ++count1);
            continue;
        }
        StepOne(a);
        StepOne(b);
        stringstream ss(a + 1);
        alength = 0;
        while (ss >> temp)
        {
            s1[++alength] = temp;
        }
        stringstream st(b + 1);
        blength = 0;
        while (st >> temp)
        {
            s2[++blength] = temp;
        }
        solve();
    }
    return 0;
}
