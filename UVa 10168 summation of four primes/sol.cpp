#include <cstdio>
#define SIZ 10010896
#define LMT 3164
#define MAX 10000000
#define LEN 665254
int flag[SIZ >> 6], primes[LEN], total;
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
#define isp(x) (x==2||(x>2&&(x&1)&&(!(ifc(x)))))
void sieve()
{
    int i, j, k;
    for (i = 3; i < LMT; i += 2) if (!ifc(i))
            for (j = i * i, k = i << 1; j < MAX; j += k) isc(j);
    primes[0] = 2, total = 1;
    for (i = 3; i < MAX; i += 2) if (!ifc(i)) primes[total++] = i;
}
int main()
{
    int n, i, j;
    sieve();
    while (scanf("%d", &n) == 1)
    {
        if (n < 8) printf("Impossible.\n");
        else
        {
            if (n & 1)
            {
                printf("2 3 ");
                n -= 5;
            }
            else
            {
                printf("2 2 ");
                n -= 4;
            }
            for (i = 0; i < total && primes[i] < n; i++)
            {
                j = n - primes[i];
                if (isp(j)) break;
            }
            printf("%d %d\n", primes[i], j);
        }
    }
    return 0;
}