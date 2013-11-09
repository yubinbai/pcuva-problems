// 由于n可达2,000,000,000，所以显式地生成这个序列不管是在时间还是空间上都不可行。

// 注意到f(n)的特点是相同的值连续出现，并且f(n)增长缓慢，这启示我们考虑其反函数g(n)，g(n)为使得f(m)=n的最大的整数m。

// 即：g(n)=max{m | f(m)=n}。

// 观察到g(n)=g(n-1)+f(n)，这很容易证明，因为g(n-1)是使得f(m)=n-1的最大的m，所以从f(g(n-1)+1)开始的一段区间的值为n，而这段区间的长度恰巧等于f(n)，因为根据定义，n恰巧出现f(n)次。

// 再注意到，根据g(n)的定义，我们容易将f(n)用g(n) 表示出来：

// f(n)=min{k | g[k]>=n}，即第一个使得g[k]>=n的整数k。

// 于是我们上面的关于g(n)的递推式可以写成：

// g{n)=g(n-1)+min{k | g[k]>=n}。

// 现在的问题是min中的k的范围如何界定，很明显，当n>2时，有k<n。

// 于是我们得到：

// g(1)=1，

// g(2)=3，

// g(i)=g(i-1)+min{k | g(k)>=i, 0<k<i}。

// 由于g(i)单调，所以min{k | g(k)>=i, 0<k<i}可以通过二分搜索快速求得。

// 所以我们可以根据这个递推式，用二分搜索预处理出g(i)的值。

// 而f(n)=min{k | g[k]>=n}，这也可以使用二分搜索求解。

#include <stdio.h>
#include <algorithm>
#define M (700000)
using std::lower_bound;
long long g[M];
void init();
int main()
{
    init();
    int n;
    while (scanf("%d", &n), n)
        printf("%d\n", lower_bound(g + 1, g + M, n) - g);
    return 0;
}
void init()
{
    g[1] = 1;
    g[2] = 3;
    for (int i = 3; i < M; ++i)
        g[i] = g[i - 1] + (lower_bound(g + 1, g + i, i) - g);
}