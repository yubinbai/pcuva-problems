#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 50;
const int MAXM = 1001;
int n, m, cnt[MAXM][27];
int ham(char *s1, char *s2)
{
    int c = 0;
    for (int i = 0; i < m; i++)
        if (s1[i] != s2[i])
            c++;
    return c;
}
int main()
{
    int T;
    char s[MAXM];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", s);
            for (int j = 0; j < m; j++)
                cnt[j][s[j] - 'A']++;
        }
        int cnth = 0;
        for (int i = 0; i < m; i++)
        {
            int maxi = 0;
            char maxchar;
            for (int j = 0; j < 26; j++)
                if (cnt[i][j] > maxi)   //隐式字典序
                {
                    maxi = cnt[i][j];
                    maxchar = j + 'A';
                }
            printf("%c", maxchar);
            cnth += n - maxi;        //累加距离值
        }
        printf("\n%d\n", cnth);
    }
    return 0;
}