#include <stdio.h>
#include <math.h>
int main()
{
    int t, a, b, c, i, d;
    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a == 0 && b == 0)
            break;
        d = 0;
        for (i = a; i <= b; i++)
        {
            c = sqrt(i);
            if (c * c == i)
                d++;
        }
        printf("%d\n", d);
    }
    return 0;
}