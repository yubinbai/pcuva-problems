#include <cstdio>
#include <cstring>
#include <cstring>
#include <cmath>

const int MAXN = 65010;
bool prime[MAXN];

void init()
{
    memset(prime, true, sizeof(prime));

    for (int i = 2; i <= (int)sqrt(MAXN * 1.0); ++i)
        if (prime[i])
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
}

long long int powmod(int a, int n, int m)
{
    if (n == 1)
        return a % m;

    long long int res;
    res = powmod(a, n >> 1, m);
    res = (res * res) % m;

    if (n % 2)
        return (a * res) % m;
    else
        return res;
}

bool judge(int n)
{
    if (prime[n])
        return false;

    for (int i = 2; i < n; ++i)
        if (powmod(i, n, n) != i)
            return false;
    return true;
}

int main()
{
    int n;
    init();
    while (scanf("%d", &n) && n)
    {
        if (judge(n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }
    return 0;
}