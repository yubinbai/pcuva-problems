#include<stdio.h>
#include<string.h>
#include "ctype.h"
#define MAXN 55
char grid[MAXN][MAXN];
char word[MAXN];
int m, n;
int match(int x, int y);
int main()
{
    int i, j, k, ok;
    int tests, searchs;
    int x, y;
    int first_test = 1;
    scanf("%d", &tests);
    for (i = 0; i < tests; i++)
    {
        if (first_test) first_test = 0;
        else printf("\n");

        scanf("%d %d", &m, &n);
        for (j = 0; j < m; j++)
        {
            scanf("%s", grid[j]);
            for (k = 0; k < strlen(grid[j]); k++)
                grid[j][k] = tolower(grid[j][k]);
        }

        scanf("%d", &searchs);
        for (j = 0; j < searchs; j++)
        {
            scanf("%s", word);
            for (k = 0; k < strlen(word); k++)
                word[k] = tolower(word[k]);
            ok = 0;
            for (x = 0; x < m; x++)
            {
                for (y = 0; y < n; y++)
                    if (grid[x][y] == word[0])
                    {
                        if (match(x, y))
                        {
                            ok = 1;
                            break;
                        }
                    }
                if (ok) break;
            }
            printf("%d %d\n", x + 1, y + 1);
        }
    }
    return 0;
}
int match(int x, int y)
{
    int len = strlen(word);
    char piece[len];
    int xd[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int yd[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int i, j;
    int xx, yy;
    for (i = 0; i < 8; i++)
    {
        xx = x;
        yy = y;
        for (j = 0; j < len && xx >= 0 && xx < m && yy >= 0 && yy < n; j++)
        {
            piece[j] = grid[xx][yy];
            xx += xd[i];
            yy += yd[i];
        }
        piece[j] = 0;
        if (strcmp(piece, word) == 0) return 1;
    }
    return 0;
}
