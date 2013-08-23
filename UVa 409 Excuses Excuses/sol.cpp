#include <stdio.h>
#include <string.h>
#include <ctype.h>

int K, E;
char k[20][21];
char e[20][71];
char f[20][71];
int c[20];

int main()
{
    int t = 0;
    while (scanf("%d %d\n", &K, &E) == 2)
    {
        printf("Excuse Set #%d\n", ++t);
        for (int i = 0; i < K; i++) gets(k[i]);
        memset(e, 0, sizeof(e));
        int m = 0;
        for (int i = 0; i < E; i++)
        {
            gets(e[i]);
            memcpy(f[i], e[i], sizeof(e[i]));
            for (int j = 0; j < 71; j++)
                if (!isalpha(e[i][j])) e[i][j] = 0;
            c[i] = 0;
            for (int j = 0; j < 70; j++)
                if (e[i][j] == 0) for (int x = 0; x < K; x++)
                        if (!strcasecmp(e[i] + j + 1, k[x])) ++c[i];
            if (c[i] > m) m = c[i];
        }
        for (int i = 0; i < E; i++) if (c[i] == m) puts(f[i]);
        puts("");
    }
    return 0;
}