#include <iostream>
#include <stdio.h>
#define MAX 50
using namespace std;
long long int FAC[MAX] = {0};
long long int factorial(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    else
    {
        if (FAC[n - 1] != 0)
        {
            return n * FAC[n - 1];
        }
        else
        {
            FAC[n - 1] = factorial(n - 1);
            return n * FAC[n - 1];
        }
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if ((n < 0 && (-1 * n) % 2 == 1) || n > 13)
        {
            printf("Overflow!\n");
        }
        else if ((n < 0 && (-1 * n) % 2 == 0) || n < 8)
        {
            printf("Underflow!\n");
        }
        else
        {
            printf("%lld\n", factorial(n));
        }
    }
    return 0;
}