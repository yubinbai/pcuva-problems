#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int sum[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int node[256], n, a[8], m, i, j, k, count = 0;
    char hg;
    while (scanf("%d\n", &n))
    {
        if (n == 0)  break;
        count++;
        for (i = 1; i <= n; i++)
        {
            scanf("x%d", &a[i]);
            getchar();
        }
        for (k = pow(2, n); k <= pow(2, n + 1) - 1; k++)
        {
            scanf("%c", &hg);
            node[k] = hg - '0';
        }
        scanf("%d\n", &m);
        printf("S-Tree #%d:\n", count);
        while (m--)
        {
            for (j = 1; j <= n; j++)
            {
                for (i = 1; i <= n; i++)
                {
                    if (a[i] == j)
                        break;
                }
                scanf("%c", &hg);
                for (k = sum[j - 1]; k <= sum[j] - 1; k++)
                    node[k] = hg - '0';
            }
            k = 1;
            getchar();
            while (1)
            {
                if (node[k])  k = 2 * k + 1;
                else k = 2 * k;
                if (k >= sum[n])
                {
                    printf("%d", node[k]);
                    break;
                }
            }
        }
        putchar('\n');
        putchar('\n');
    }
    return 0;
}