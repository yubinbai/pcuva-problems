#include <stdio.h>
#include <string.h>
#define N 10000
int d[N], s[N], sum[N], top;
int main()
{
    int i, n, num, flag;
    char c;
    while (scanf ("%d", &d[0]) != EOF)
    {
        c = getchar();
        n = 1; top = -1; flag = 1;
        memset (sum, 0, sizeof(sum[0])*N);
        while (c != '\n')
        {
            scanf ("%d", &d[n]);
            c = getchar(); n++;
        }
        for (i = 0; i < n; i++)
        {
            if (d[i] < 0)
            {
                s[++top] = d[i];
            }
            else
            {
                if (top < 0 || s[top] != -1 * d[i] || d[i] <= sum[top])
                {
                    flag = 0;
                    break;
                }
                else
                {
                    sum[top] = 0;
                    top--;
                    if (top >= 0)
                        sum[top] += d[i];
                }
            }
        }
        if (top == -1 && flag == 1) printf (":-) Matrioshka!\n");
        else printf (":-( Try again.\n");
    }
    return 0;
}