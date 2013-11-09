#include<stdio.h>
int main()
{
    unsigned int n, i, p;
    while (scanf("%d", &n) == 1)
    {
        for (p = 1, i = 0; p < n; i++)
        {
            if (i & 1) p <<= 1;
            else p += (p << 3);
        }
        puts(((i & 1) ? "Stan wins." : "Ollie wins."));
    }
    return 0;
}