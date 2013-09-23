#include<stdio.h>

int d, x, y;
void extEuclid(int, int);

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2)
    {
        extEuclid(a, b);
        printf("%d %d %d\n", x, y, d);
    }
    return 0;
}

void extEuclid(int a, int b)
{
    int x1;

    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    extEuclid(b, a % b);

    x1 = x - (a / b) * y;
    x = y;
    y = x1;
}
