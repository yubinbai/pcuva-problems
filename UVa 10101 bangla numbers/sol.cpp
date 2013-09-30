#include <cstdio>
const char *z[4] = {"shata", "hajar", "lakh", "kuti"};
int div[4] = {10, 100, 100, 100};
void bangla(long long n, int pos)
{
    if (!n) return;
    bangla(n / div[pos], (pos + 1) % 4);
    int ndivpos = n % div[pos];
    if (ndivpos) printf(" %lld %s", n % div[pos], z[pos]);
    else if (pos == 3) printf(" kuti");
}
int main(void)
{
    int cnum = 0;
    for (long long n; scanf("%lld", &n) == 1; puts(""))
    {
        printf("%4d.", ++cnum);
        bangla(n / 100, 0);
        if (!(n / 100) || n % 100) printf(" %lld", n % 100);
    }
    return 0;
}