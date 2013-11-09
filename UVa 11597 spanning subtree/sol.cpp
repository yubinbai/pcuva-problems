// in an complete graph you have n*(n-1)/2 edges
// and you need n-1 edges to form each spanning tree.

#include<stdio.h>
int main()
{
    int a, i = 1;
    while (scanf("%d", &a) == 1 && a > 1)
    {
        printf("Case %d: %d\n", i, a / 2);
        i++;
    }
    return 0;
}