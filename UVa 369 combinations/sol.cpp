#include <cstdio>
using namespace std;

long long a[101][101];

int main()
{
    int n, m;
    a[1][1] = 1;
    a[1][0] = 1;

    for (int n = 2; n <= 100; n++)
    {
        a[n][0] = 1;
        for (int k = 1; k <= n; k++)
        {
            a[n][k] = a[n - 1][k] + a[n - 1][k - 1];
        }
    }

    while (scanf("%d%d", &n, &m), n || m)
    {
        printf("%d things taken %d at a time is %lld exactly.\n", n, m,
               a[n][m]);
    }

    return 0;
}