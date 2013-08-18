/*
dp[i][j]表示a串前i个字符和b串前j个字符的最短编辑距离
1.dp[i][j]=dp[i-1][j]+1 即先删除a串的第i个字符，然后使其前i-1个字符与b串的前j个字符相同
2.dp[i][j]=dp[i][j-1]+1 即先让a串的前i个字符和b串的前j-1个字符相同，然后再在a串后面插入b[j]这个字符
3.dp[i][j]=dp[i-1][j-1]+(a[i]==b[j]?0:1)
  即先让a串前i-1个字符和b串前j-1个字符相同，看a[i]是否等于b[j]，等于的话不需要操作，不等让a[i]变为b[j]
dp[i][j]=min{1,2,3}
最后来解决一下如何保存路径的问题,p[i][j]=1,2,3，表示得到dp[i][j]的时候是用了第几个策略
p[i][j]=1，说明用了策略1，是删除了a[i]，所以输出删除对应的语句，注意此时对应的位置是j+1，并接着去到p[i-1][j]
p[i][j]=2，说明用了策略2，是插入了b[j]，所以输出插入对应的语句，注意此时对应的位置是j，并接着去到p[i][j-1]
p[i][j]=0，说明用了策略3，但没有更换，不用输出，并接着去到p[i-1][j-1]
p[i][j]=3，说明用了策略3，是更换了a[i]，所以输出更换对应的语句，注意此时对应的位置是j，并接着去到p[i-1][j-1]
p数组初始化为-1，p[i][j]=-1，则说明路径到达了尽头，或者(i==0 && j==0)也是尽头标志，表示a串和b串都已经递归处理完
*/
#include <cstdio>
#include <cstring>
#define N 25
#define INF 0x3f3f3f3f

char a[N], b[N];
int dp[N][N], p[N][N];

int min(int i , int j , int *s)
{
    int f, k;
    for (k = 1; k <= 3; k++)
        if (s[k] < dp[i][j])
        {
            dp[i][j] = s[k];
            f = k;
        }
    if (f == 3 && a[i] == b[j]) f = 0;
    return f;
}

void print(int i , int j)
{

    if (!i && !j) return ;
    else if (p[i][j] == 1) //删除a串第i个字符
    {
        print(i - 1, j);
        printf("D%c%02d", a[i], j + 1);
        return ;
    }
    else if (p[i][j] == 2) //在a串最后（第i个字符后）插入字符b[j]
    {
        print(i, j - 1);
        printf("I%c%02d", b[j], j);
        return ;
    }
    else if (p[i][j] == 0) //什么都不做
    {
        print(i - 1, j - 1);
        return ;
    }
    else //把a[i]变为b[j]
    {
        print(i - 1, j - 1);
        printf("C%c%02d", b[j], j);
        return ;
    }
}

int main()
{
    int lena, lenb;
    while (1)
    {
        scanf("%s", a + 1);
        if (a[1] == '#') break;
        scanf("%s", b + 1);
        lena = strlen(a + 1); lenb = strlen(b + 1);
        memset(dp, 0x3f, sizeof(dp));
        memset(p, -1, sizeof(p));
        for (int i = 0; i <= lena; i++)
        {
            dp[i][0] = i;
            p[i][0] = 1;
        }
        for (int i = 0; i <= lenb; i++)
        {
            dp[0][i] = i;
            p[0][i] = 2;
        }
        //dp[1][1]=(a[1]==b[1]?0:1);

        for (int i = 1; i <= lena; i++)
            for (int j = 1; j <= lenb; j++)
            {
                int s[4];
                s[1] = dp[i - 1][j] + 1;
                s[2] = dp[i][j - 1] + 1;
                s[3] = dp[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1);
                p[i][j] = min(i, j, s);
            }
        //printf("最短编辑距离:%d\n",dp[lena][lenb]);
        print(lena , lenb);
        printf("E\n");
    }
    return 0;
}