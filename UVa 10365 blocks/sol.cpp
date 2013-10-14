#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n, i, j, k, area = 1000000000;
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i * j > n)
                    break;
                for (k = 1; k <= n; k++)
                {
                    if (i * j * k > n)
                        break;
                    if (i * j * k == n)
                    {
                        int temp = 2 * (i * j + j * k + k * i);
                        area = area <= temp ? area : temp;
                    }
                }
            }
        }
        printf("%d\n", area);
    }
    return 0;
}