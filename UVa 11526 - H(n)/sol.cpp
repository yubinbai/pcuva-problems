#include <cstdio>
#include <cmath>

long long H(int n)
{
    if (n < 0)
        return 0;
    if (n == 1)
        return 1;
    long long result = n;
    int cur_divisor = 2, cur_quoitent, prev_divisor = 1, prev_quoitent = n;
    while (true)
    {
        cur_quoitent = n / cur_divisor;
        result +=
            static_cast<long long>(prev_quoitent - cur_quoitent) * prev_divisor;
        if (cur_quoitent >= cur_divisor)
            result += cur_quoitent;
        if (cur_quoitent <= cur_divisor)
            break;
        prev_divisor = cur_divisor++;
        prev_quoitent = cur_quoitent;
    }
    return result;
}

int main()
{
    int t;
    scanf("%d", & t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", H(n));
    }
    return 0;
}