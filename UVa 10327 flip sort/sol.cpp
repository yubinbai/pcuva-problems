#include <cstdio>
using namespace std;

#define max 1000

int main(void)
{
    int a[max], i, t, j, k, n, count, temp;
    while (scanf("%d", &n) == 1)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        count = 0;
        for (i = 1; i < n; i++)
        {
            k = 1;
            for (j = 0; j < n - i; j++)
                if (a[j] > a[j + 1])
                {
                    count++;
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    k = 0;
                }
            if (k == 1)
                break;
        }
        printf("Minimum exchange operations : %d\n", count);
    }
    return 0;
}