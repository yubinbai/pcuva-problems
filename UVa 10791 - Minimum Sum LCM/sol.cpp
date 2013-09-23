#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX_PRIME 2147483647
using namespace std;
int cnt;
long long sum;
int main()
{
    int curCase = 1;
    int n, i, least;

    while (scanf("%d", &n), n)
    {
        sum = 0;
        least = sqrt(n + 1);
        printf("Case %d: ", curCase++);

        for (i = 2, cnt = 0; i <= least; i ++)
        {
            if (n % i == 0)
            {
                long long tmp = 1;
                cnt ++;
                while (n % i == 0)
                {
                    tmp *= i;
                    n /= i;
                }
                sum += tmp;
            }
        }
        if (n != 1 || cnt == 0)
        {
            cnt ++;
            sum += n;
        }
        if (cnt == 1)    sum ++;

        printf("%lld\n", sum);
    }
    return 0;
}