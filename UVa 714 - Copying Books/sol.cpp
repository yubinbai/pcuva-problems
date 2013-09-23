#include<cstdio>
#include<cstring>
#define MAXN 505
using namespace std;
int m, k;
long long arr[MAXN], sum, min, ans;
bool vis[MAXN];
inline int divide(long long M)
{
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    int pos = m - 1;
    while (pos >= 0)
    {
        long long sum = 0;
        bool ok = true;
        while (pos >= 0 && sum + arr[pos] <= M)
        {
            ok = false;
            sum += arr[pos];
            --pos;
        }
        if (ok)
        {
            return k + 1;
        }
        if (pos >= 0) vis[pos] = true;
        ++cnt;
    }
    return cnt;
}
long long binary()
{
    long long left = min, right = sum, mid;
    while (left < right)
    {
        mid = (left + right) >> 1;
        if (divide(mid) <= k)
            right = mid;
        else
            left = mid + 1;
    }
    return right;
}
inline void output()
{
    int cnt = divide(ans);
    for (int i = 0; i < m - 1 && cnt < k; ++i)if (!vis[i])
        {
            vis[i] = true;
            ++cnt;
        }
    for (int i = 0; i < m; ++i)
    {
        if (i) printf(" %lld", arr[i]);
        else printf("%lld", arr[i]);
        if (vis[i])
        {
            printf(" /");
        }
    }
    puts("");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &m, &k);
        sum = 0;  min = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%lld", &arr[i]);
            sum += arr[i];
            if (arr[i] > min) min = arr[i];
        }
        ans = binary();
        output();
    }
    return 0;
}
