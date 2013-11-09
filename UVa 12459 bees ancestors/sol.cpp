#include <stdio.h>
int main()
{
    long long arr[81];
    int x, i;
    arr[0] = 1;
    arr[1] = 1;
    for (i = 2; i < 81; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    while (1)
    {
        scanf("%d", &x);
        if (x == 0)
            break;
        printf("%lld\n", arr[x]);
    }
    return 0;
}