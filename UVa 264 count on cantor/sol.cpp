#include <cstdio>
#include <cmath>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int k = (int)(sqrt(2 * n) - 1);
        while (n > k * (k + 1) / 2)
            k++;
        int num = n - (k - 1) * k / 2;
        int a, b;
        if (k % 2)
        {
            b = num;
            a = k + 1 - num;
        }
        else
        {
            a = num;
            b = k + 1 - num;
        }
        printf("TERM %d IS %d/%d\n", n, a, b);
    }
    return 0;
}