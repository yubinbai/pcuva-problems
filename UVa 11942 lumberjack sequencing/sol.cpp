#include<stdio.h>

int main()
{
    int t, i, j, k, value[12], as, de;
    while (scanf("%d", &t) == 1)
    {
        for (i = 1; i <= t; i++)
        {
            for (j = 1; j <= 10; j++)
                scanf("%d", &value[j]);
            as = 0;
            de = 0;
            if (i == 1)
                printf("Lumberjacks:\n");
            if (value[1] > value[2])
                for (k = 1; k < 10; k++)
                {
                    if (value[k] > value[k + 1])
                        de++;
                    else
                        break;
                }
            else if (value[1] < value[2])
                for (k = 1; k < 10; k++)
                {
                    if (value[k] < value[k + 1])
                        as++;
                    else
                        break;
                }
            if (as == 9 || de == 9)
                printf("Ordered\n");
            else
                printf("Unordered\n");
        }

    }
    return 0;
}
