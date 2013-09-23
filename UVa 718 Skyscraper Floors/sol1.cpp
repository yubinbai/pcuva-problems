#include <math.h>
#include <stdio.h>
#include <string.h>

unsigned char r[100];

long long gcd(long long a, long long b, long long *x, long long *y)
{
    long long g, u, v;
    if (a < b)
        return gcd(b, a, y, x);
    if (b == 0)
    {
        *x = 1, *y = 0;
        return a;
    }
    else
    {
        g = gcd(b, a % b, &u, &v);
        *x = v, *y = u - a / b * v;
        return g;
    }
}

int dfs(unsigned char g[100][100], int i, int j, int n)
{
    int k;
    if (g[i][j])
        return 1;
    for (r[i] = 0, k = n; k--;)
        if (g[i][k] && r[k] && dfs(g, k, j, n))
            return 1;
    return 0;
}

int main()
{
    long long a, b, e, f, i, j, k, m, n, p, q, u, v, x[100], y[100];
    unsigned char g[100][100];
    double s, t;

    scanf("%lld", &n);
    while (n--)
    {
        memset(g, 0, sizeof(g));
        memset(r, 1, sizeof(r));
        scanf("%lld %lld %lld %lld", &f, &e, &a, &b);
        for (i = 0; i < e; ++i)
            scanf("%lld %lld", &x[i], &y[i]);
        for (i = e; i--;)
        {
            for (j = i; j--;)
            {
                k = gcd(x[i], x[j], &u, &v);
                if ((m = y[j] - y[i]) % k) continue;
                m /= k, u *= m, v *= m;
                s = (double) - (x[i] * u + y[i]) * k / (x[i] * x[j]);
                t = ceil(s), s = floor(s);
                p = u + (long long)s * x[j] / k;
                q = v - (long long)s * x[i] / k;
                if (0 <= x[i] * p + y[i] && x[i] * p + y[i] < f)
                    g[i][j] = g[j][i] = 1;
                p = u + (long long)t * x[j] / k;
                q = v - (long long)t * x[i] / k;
                if (0 <= x[i] * p + y[i] && x[i] * p + y[i] < f)
                    g[i][j] = g[j][i] = 1;
            }
        }
        for (u = e; u--;)
            if ((a - y[u]) % x[u] == 0)
                break;
        for (v = e; v--;)
            if ((b - y[v]) % x[v] == 0)
                break;
        if (u < 0 || v < 0 || dfs(g, u, v, e) == 0)
            puts("The furniture cannot be moved.");
        else
            puts("It is possible to move the furniture.");
    }

    return 0;
}