#include <stdio.h>
int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
        printf("%10d%10d    %s Choice\n\n", a, b, (gcd(a, b) == 1) ? "Good" : "Bad");
    return 0;
}