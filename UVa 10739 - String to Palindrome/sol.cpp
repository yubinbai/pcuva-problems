#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000 + 10, INF = (1 << 30);
int d[maxn][maxn];
char s[maxn];

int min(int a, int b, int c)        //求三数最小数
{
    a = (a < b) ? a : b;
    a = (a < c) ? a : c;
    return a;
}
int dp(int i, int j)
{
    int &ans = d[i][j];
    if (ans != INF) return ans;
    if (j == i + 1)
    {
        if (s[i] == s[j]) return ans = 0;
        else return ans = 1;
    }
    if (s[i] == s[j])       //两端相等
        ans = dp(i + 1, j - 1);
    else        //两端不等可增、删、改
        ans = min(dp(i, j - 1), dp(i + 1, j), dp(i + 1, j - 1)) + 1;
    return ans;
}
int main()
{
    int T, i, j, cnt = 1;
    scanf("%d", &T);
    while (T--)
    {
        getchar();
        cin >> (s + 1);
        int len = strlen(s + 1);
        for (i = 0; i < maxn; i++)
        {
            for (j = 0; j < maxn; j++)
                d[i][j] = INF;
            d[i][i] = 0;
        }
        dp(1, len);
        printf("Case %d: %d\n", cnt++, d[1][len]);
    }
    return 0;
}
