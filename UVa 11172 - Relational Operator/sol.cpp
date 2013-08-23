#include<stdio.h>
int main()
{
    long int c, a, b, i;
    while (scanf("%ld", &c) == 1)
    {
        for (i = 1; i <= c; i++)
        {
            scanf("%ld%ld", &a, &b);
            if (a > b) printf(">\n");
            else if (a < b) printf("<\n");
            else printf("=\n");
        }
    }
    return 0;
}