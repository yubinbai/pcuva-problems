#include<stdio.h>
int main()
{
    int n, t = 1;
    long int a, b, c;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%ld%ld%ld", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b && a == c && b == c)
                printf("Case %d: Equilateral\n", t);
            else if (a != b && a != c && b != c) printf("Case %d: Scalene\n", t);
            else printf("Case %d: Isosceles\n", t);
        }
        else printf("Case %d: Invalid\n", t);
        t++;
    }
}