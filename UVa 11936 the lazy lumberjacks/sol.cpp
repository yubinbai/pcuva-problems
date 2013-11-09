#include<stdio.h>
int main()
{
    int a, b, c, i, t;
    while (scanf("%d", &t) == 1)
    {
        for (i = 0; i < t; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if (a + b <= c || b + c <= a || a + c <= b)
                printf("Wrong!!\n");
            else
                printf("OK\n");
        }
    }
}