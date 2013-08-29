#include <stdio.h>
int main()
{
    double n;
    while (scanf("%lf", &n) && n >= 0)
    {
        if (n <= 1)
            printf("0%%\n");
        else
            printf("%.0lf%%\n", 25 * n);
    }
    return 0;
}