#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 70000;
int a[N];
int main()
{
    int cnt = 2;
    a[1] = 1;
    while (1)
    {
        a[cnt] = a[cnt - 1] + cnt;
        if (a[cnt] > 1000000000) break;
        cnt++;
    }
    int t, t_cnt = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 1;
        scanf("%d", &n);
        if (n < 0) n = -n;
        while (ans < cnt)
        {
            if (a[ans] >= n && (a[ans] - n) % 2 == 0) break;
            ans++;
        }
        if (t_cnt++ != 0) puts("");
        printf("%d\n", ans);
    }
    return 0;
}
