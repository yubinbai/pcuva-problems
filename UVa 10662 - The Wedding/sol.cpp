#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *t, *r, *h, a, b, c, i, j, k, x, y, z, min;
    char **tr, **rh, **ht;
    while (scanf("%d %d %d", &a, &b, &c) == 3)
    {
        t = (int *) malloc(a * sizeof(int));
        r = (int *) malloc(b * sizeof(int));
        h = (int *) malloc(c * sizeof(int));
        tr = (char **) malloc(a * sizeof(char *));
        rh = (char **) malloc(b * sizeof(char *));
        ht = (char **) malloc(c * sizeof(char *));
        for (i = 0; i < a; i++)
        {
            tr[i] = (char *) malloc(b);
        }
        for (i = 0; i < b; i++)
        {
            rh[i] = (char *) malloc(c);
        }
        for (i = 0; i < c; i++)
        {
            ht[i] = (char *) malloc(a);
        }
        for (i = 0; i < a; i++)
        {
            scanf("%d", &t[i]);
            for (j = 0; j < b; j++)
            {
                scanf("%d", &tr[i][j]);
            }
        }
        for (i = 0; i < b; i++)
        {
            scanf("%d", &r[i]);
            for (j = 0; j < c; j++)
            {
                scanf("%d", &rh[i][j]);
            }
        }
        for (i = 0; i < c; i++)
        {
            scanf("%d", &h[i]);
            for (j = 0; j < a; j++)
            {
                scanf("%d", &ht[i][j]);
            }
        }
        x = y = z = -1;
        min = 2147483647;
        for (i = 0; i < a; i++)
            for (j = 0; j < b; j++)
                if (!tr[i][j])
                    for (k = 0; k < c; k++)
                    {
                        if (!rh[j][k] && !ht[k][i] && t[i] + r[j] + h[k] < min)
                        {
                            min = t[i] + r[j] + h[k];
                            x = i;
                            y = j;
                            z = k;
                        }

                    }
        if (x != -1)
        {
            printf("%d %d %d:%d\n", x, y, z, min);
        }
        else
            printf("Don't get married!\n");
    }
    return 0;
}