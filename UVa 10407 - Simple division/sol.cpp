#include <stdio.h>
int abs(int a)
{
    return (a >= 0) ? a : -a;
}
int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
    int inp[1001], i, j, n, g;
    while (1)
    {
        scanf("%d", inp);
        if (inp[0] == 0)
            break;
        int top = 1;
        while (scanf("%d", inp + top) && inp[top] != 0)
            top++;
        g = 0;
        for (i = 0; i < top; i++)
            for (j = i + 1; j < top; j++)
                if (inp[i] - inp[j] != 0)
                    g = gcd(abs(inp[i] - inp[j]), g);
        printf("%d\n", g);

    }
    return 0;
}