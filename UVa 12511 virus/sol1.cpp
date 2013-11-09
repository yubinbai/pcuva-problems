// 经典的动态规划优化。

// 用opt[i][j]表示s[0..i-1]与t[0..j-1]的以t[j-1]结尾的最长上升公共子序列的长度，那么最后的答案是max{opt[n][j]
// | 1<=j<=m}。

// 当s[i-1]!=t[j-1]时，由于必须以t[j-1]收尾，所以不可能选择s[i-1]，故有：

// opt[i][j]=opt[i-1][j]。

// 当s[i-1]=t[j-1]时，与LIS一样，我们有：

// opt[i][j]=1+max{opt[i-1][k] | k<j,t[k]<t[j]}。

// 如果直接求解这个状态转移方程，时间复杂度是O(n^3)，我们需要进行优化，由于主要的时间消耗出现在s[i]=t[j]的情况下，
// 所以我们对这种情况的求解进行优化。

// 我们按照i优先的顺序求解（外层循环为i），那么注意到在求解opt[i][j]时，主要的工作量是计算max{opt[i-1][k] |
// k<j,t[k]<t[j]}，然而如果我们利用以前已经求解过的opt[][]的值，可以直接得到opt[i][j]=1+max{opt[i-1][k]
// | k<j,t[k]<t[j]}的值而不用枚举，假设在t[j]之前有一个t[p]满足t[p]=t[j]
// （p<j），那么我们在求解opt[i][p]的时候已经得到了max{opt[i-1][k] |
// k<p,t[k]<t[p]}，所以在求解opt[i][j]时，对于k<p，我们不用再比较opt[i-1][k]
// |，他们的最大值就等于opt[i][p]-1，所以我们可以记录最大的p，然后在求解opt[i][j]时，只对大于p的k作比较，
// 另一方面，如果对于t[p]与t[k]之间的t的元素，我们显然不需要考虑那些不小于t[j]的，又因为t[j]=s[i]，
// 所以实际上我们只需要取max{opt[i-1][k] | p<k<j,t[k]<s[i]}与opt[i][p]-1的最大值，鉴于此，我们得到如下的做法：

// 在每次内层循环（求解j）前，维护一个mx变量，它维护max{opt[i-1][k] |
// k<j,t[k]<t[j]=s[i]}的值，然后循环j，如果遇到t[j]<s[i]，则更新mx=max{mx,opt[i-1][j]，
// 当出现t[j]=s[i]时，有opt[i][j]=mx+1。

// 这样时间复杂度降为O(n^2)。
#include <stdio.h>
#include <string.h>
#define N (1111)
#define MAX(x,y) ((x)>(y)?(x):(y))
int n, m, s[N], t[N], opt[N][N];
void init();
int dp();
int main()
{
    int nprob;
    scanf("%d", &nprob);
    while (nprob--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", s + i);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", t + i);
        init();
        printf("%d\n", dp());
    }
}
void init()
{
    memset(opt, 0, sizeof(opt));
}
int dp()
{
    for (int i = 1; i <= n; ++i)
    {
        int mx = 0;
        for (int j = 1; j <= m; ++j)
            if (s[i - 1] == t[j - 1])
                opt[i][j] = mx + 1;
            else
            {
                opt[i][j] = opt[i - 1][j];
                if (t[j - 1] < s[i - 1])
                    mx = MAX(mx, opt[i][j]);
            }
    }
    int ret = 0;
    for (int j = 1; j <= m; ++j)
        ret = MAX(ret, opt[n][j]);
    return ret;
}