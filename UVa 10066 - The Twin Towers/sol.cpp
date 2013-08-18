#include <stdio.h>
#include <string.h>

int LCS[1024][1024];


int main()
{

    int length, j, i, m, n, x, test = 1;
    int s[1010], t[1010];
    while (scanf("%d %d", &m, &n) == 2 && !(m == 0 && n == 0))
    {
        printf("Twin Towers #%d\n", test);
        test++;
        for (x = 0; x < m; x++)
            scanf("%d", &s[x]);
        for (x = 0; x < n; x++)
            scanf("%d", &t[x]);

        for ( i = 0; i <= m; i++ ) LCS[i][n] = 0;
        for ( j = 0; j <= n; j++ ) LCS[m][j] = 0;

        for (i = m - 1; i >= 0; i--)
        {
            for ( j = n - 1; j >= 0; j--)
            {
                LCS[i][j] = LCS[i + 1][j + 1];
                if ( s[i] == t[j] ) LCS[i][j]++;

                if ( LCS[i][j + 1] > LCS[i][j] ) LCS[i][j] = LCS[i][j + 1];
                if ( LCS[i + 1][j] > LCS[i][j] ) LCS[i][j] = LCS[i + 1][j];
            }
        }
        printf("Number of Tiles : %d\n\n", LCS[0][0]);
    }

    return 0;
}