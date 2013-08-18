#include <stdio.h>
#include <string.h>
#define N (500)
#define MAX(x,y) ((x)>(y)?(x):(y))
struct bign
{
    int n, dig[N];
};
void add(bign &a, bign &b, bign &c);
int cmp(bign &a, bign &b);
int read(bign &a, bign &b);
void init();
bign zero, fib[N];
int main()
{
    init();
    bign a, b;
    while (read(a, b), cmp(a, zero) || cmp(b, zero))
    {
        int c = 0;
        for (int i = 1; i < N; ++i)
            if (cmp(a, fib[i]) <= 0 && cmp(fib[i], b) <= 0)
                ++c;
        printf("%d\n", c);
    }
    return 0;
}
void init()
{
    memset(&zero, 0, sizeof(zero));
    memset(fib, 0, sizeof(fib));
    zero.n = 1;
    fib[1].n = 1;
    fib[1].dig[1] = 1;
    fib[2].n = 1;
    fib[2].dig[1] = 2;
    for (int i = 3; i < N; ++i)
        add(fib[i - 2], fib[i - 1], fib[i]);
}
int read(bign &a, bign &b)
{
    char s[N], t[N];
    int ret = scanf("%s%s", s, t);
    memset(&a, 0, sizeof(a));
    memset(&b, 0, sizeof(b));
    a.n = strlen(s);
    b.n = strlen(t);
    for (int i = a.n; i; --i)
        a.dig[a.n - i + 1] = s[i - 1] - '0';
    for (int i = b.n; i; --i)
        b.dig[b.n - i + 1] = t[i - 1] - '0';
    return ret;
}
void add(bign &a, bign &b, bign &c)
{
    int n = MAX(a.n, b.n), r = 0;
    memset(&c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i)
    {
        c.dig[i] = a.dig[i] + b.dig[i] + r;
        r = c.dig[i] / 10;
        c.dig[i] %= 10;
    }
    if (r)
        c.dig[++n] = r;
    c.n = n;
}
int cmp(bign &a, bign &b)
{
    if (a.n < b.n)
        return -1;
    if (a.n > b.n)
        return 1;
    for (int i = a.n; i; --i)
        if (a.dig[i] < b.dig[i])
            return -1;
        else if (a.dig[i] > b.dig[i])
            return 1;
    return 0;
}