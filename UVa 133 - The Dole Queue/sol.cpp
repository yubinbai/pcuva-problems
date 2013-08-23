#include <cstdio>
using namespace std;

const int maxn = 25;
int a[maxn];
int size;

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) != EOF && !(!n && !k && !m))
    {
        int first = 1;
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        size = n;
        int p = n - 1, q = 0;
        while (size > 0)
        {
            for (int cnt = 0; cnt < k; )
            {
                p = (p + 1) % n;
                if (a[p])   cnt++;
            }
            for (int cnt = 0; cnt < m; )
            {
                q = (q - 1 + n) % n;
                if (a[q])   cnt++;
            }
            if (first)   first = 0;
            else printf(",");
            if (p == q)
            {
                printf("%3d", a[p]);
                a[p] = 0;
                size--;
            }
            else
            {
                printf("%3d%3d", a[p], a[q]);
                a[p] = a[q] = 0;
                size -= 2;
            }
        }
        printf("\n");
    }
    return 0;
}