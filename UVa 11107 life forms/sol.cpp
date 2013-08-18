#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (10000000+10)
#define MAXL (10001000+10)

int sa[MAXL], w[MAXN], wa[MAXL * 2] = {0}, wb[MAXL * 2] = {0};
bool cmp(int *a, int x, int y, int j)
{
    return a[x] == a[y] && a[x + j] == a[y + j];
}
void suffix_array(char *s, int n, int m)
{
    int *x = wa, *y = wb;
    For(i, m) w[i] = 0;
    For(i, n) w[x[i] = s[i]]++;
    Fork(i, 2, m) w[i] += w[i - 1];
    ForD(i, n) sa[w[x[i]]--] = i;
    for (int j = 1, p = 0; p < n; j *= 2, m = p)
    {
        p = 0;
        Fork(i, n - j + 1, n) y[++p] = i;
        For(i, n) if (sa[i] > j) y[++p] = sa[i] - j;
        For(i, m) w[i] = 0;
        For(i, n) w[x[i]]++;
        Fork(i, 2, m) w[i] += w[i - 1];
        ForD(i, n) sa[w[x[y[i]]]--] = y[i];
        p = y[sa[1]] = 1;
        Fork(i, 2, n)
        y[sa[i]] = (p += (!cmp(x, sa[i], sa[i - 1], j)));
        int *t = x; x = y; y = t;
    }
}
int rank[MAXL], height[MAXL];
void make_height(char *s, int n)
{
    height[1] = 0;
    For(i, n) rank[sa[i]] = i;
    For(i, n)
    {
        if (rank[i] == 1) continue;
        height[rank[i]] = max(height[rank[i - 1]] - 1, 0);
        while (s[i + height[rank[i]]] == s[sa[rank[i] - 1] + height[rank[i]]]) height[rank[i]]++;
    }
}
int n, pre[MAXN], tai[MAXN];
char s[MAXL];
int b[MAXN] = {0}, belong[MAXL];
int st[2][MAXL] = {0}, size[2] = {0}, now_col = 1;
int check(int *st, int &size, int p)
{
    memset(b, 0, sizeof(b)); now_col = 1;
    int tot = 1; size = 0;
    b[belong[sa[1]]] = now_col;
    Fork(i, 2, pre[n + 1] - 1)
    if (height[i] >= p)
    {
        if (b[belong[sa[i]]]^now_col) b[belong[sa[i]]] = now_col, tot++;
    }
    else
    {
        if (tot > n / 2) st[++size] = sa[i - 1];
        tot = 1;
        now_col++;
        b[belong[sa[i]]] = now_col;
    }
    return size;
}
char fillchar[MAXN];
int main()
{
    int p = 0;
    For(i, 'a' - 1) fillchar[++p] = i;
    for (int i = 'z' + 1; p <= 100; i++) fillchar[++p] = i;
    bool b = 0;
    while (scanf("%d", &n))
    {
        if (n)
        {
            if (b) puts("");
        }
        else break;
        pre[1] = 1;
        For(i, n)
        {
            scanf("%s", s + pre[i]); tai[i] = strlen(s + pre[i]);
            s[pre[i] + tai[i]] = fillchar[i]; pre[i + 1] = pre[i] + tai[i] + 1;
            Fork(j, pre[i], pre[i] + tai[i]) belong[j] = i;
        }
        s[pre[n + 1]] = 0;
        suffix_array(s, pre[n + 1] - 1, 200);
        make_height(s, pre[n + 1] - 1);
        int l = 1, r = pre[n + 1] - 1, ans = 0, p = 0;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(st[p], size[p], m)) ans = m, l = m + 1, p ^= 1;
            else r = m - 1;
        }
        if (ans == 0) puts("?");
        else
        {
            p ^= 1;
            For(i, size[p])
            {
                Fork(k, st[p][i], st[p][i] + ans - 1) cout << s[k];
                cout << endl;
            }
        }
        b = 1;
    }
    return 0;
}