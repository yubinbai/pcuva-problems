#include <stdio.h>

int main()
{
    int x, y, i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        // each round will reduce (y-1) people
        // only one person is left
        if ((x - 1) % (y - 1) != 0)
        {
            puts("cannot do this");
        }
        else
        {
            printf("%d\n", (x - 1) / (y - 1));
        }
    }
    return 0;
}