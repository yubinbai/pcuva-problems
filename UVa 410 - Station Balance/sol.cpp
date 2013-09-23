#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int compare (const void *a, const void *b)
{
    return ( *(int *)a - * (int *)b );
}
int main()
{
    int c, s, test;
    test = 1;
    while (scanf("%d %d", &c, &s) == 2)
    {

        int i, j;
        int zeros = 2 * c - s;
        int a[zeros + s];
        for (i = 0; i < zeros; i++)
            a[i] = 0;
        s = s + zeros;
        for (j = i; j < s; j++)
        {
            scanf("%d", &a[j]);
        }
        qsort(a, s, sizeof(int), compare);
        int ans[c][2];
        for (int i = 0; i < s / 2; i++)
        {
            ans[i][0] = a[i];
            ans[i][1] = a[s - i - 1];

        }

        printf("Set #%d\n", test++);
        for (i = 0; i < c; i++)
        {
            printf(" %d:", i);
            if (ans[i][0] != 0)
                printf(" %d %d\n", ans[i][0], ans[i][1]);
            else if (ans[i][1] != 0)
                printf(" %d\n", ans[i][1]);
            else printf("\n");
        }
        double A, imbalance;
        imbalance = 0;
        A = 0;
        for (i = 0; i < s; i++)
            A = A + a[i];
        A = A / (c);
        double x = 0;
        for (i = 0; i < c; i++)

        {
            x = ans[i][0] + ans[i][1] - A;
            if (x < 0)
                x = x * -1;
            imbalance = imbalance + x;
        }
        printf("IMBALANCE = %0.5lf", imbalance);
        printf("\n\n");

    }
    return 0;
}