#include <iostream>
#include "memory.h"
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int test, i;
    scanf("%d", &test);
    for (i = 0; i < test; i++)
    {
        int n, j;
        scanf("%d", &n);
        int sum[n], carry = 0;
        memset(sum, 0, sizeof(sum));
        for (j = 0; j < n; j++)
        {
            int a = 0, b = 0;
            scanf("%d%d", &a, &b);
            sum[j] = a + b;
        }
        for (j = n - 1 ; j >= 0; j--)
        {
            int temp = sum[j];
            sum[j] = (temp + carry) % 10;
            carry = (temp + carry) / 10;
        }
        for (j = 0; j < n; j++)
            printf("%d", sum[j]);
        printf("\n");
        if (i < test - 1)
            printf("\n");
    }
    return 0;
}