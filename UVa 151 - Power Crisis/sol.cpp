#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0) break;
        int x[n + 1];
        for (m = 1;; m++)
        {
            for (i = 1; i <= n; i++) x[i] = 0;
            i = j = 1;
            x[1] = 1;
            while (j < n)
            {
                for (k = 1; k <= m; i++)
                {
                    if (x[i] == 0) k++;
                    else if (i > n) i = 1;
                }
                x[i - 1] = 1;
                j++;
            }

            if (i - 1 == 13)
            {
                printf("%d\n", m);
                break;
            }

        }
    }
    return 0;
}