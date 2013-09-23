#include <stdio.h>
#include <stdlib.h>
void visit(int i, int j, char **map)
{
    if (map[i][j] == ' ' || map[i][j] == '*')
    {
        map[i][j] = '#';
        visit(i + 1, j, map);
        visit(i, j + 1, map);
        visit(i - 1, j, map);
        visit(i, j - 1, map);
    }
}
int main()
{
    int c, i, j, k, top;
    char **map;
    map = (char **)malloc(40 * sizeof(char *));
    for (i = 0; i < 40; i++)
        map[i] = (char *) malloc(100);
    scanf("%d\n", &c);
    while (c-- > 0)
    {
        top = 0;
        while (gets(map[top]) && map[top++][0] != '_');
        for (i = 0; i < 100; i++)
            map[top][i] = 0;
        for (i = 0; map[i][0] != '_'; i++)
        {
            for (j = 0; map[i][j]; j++)
            {
                if (map[i][j] == '*')
                {
                    visit(i, j, map);
                }
            }
        }
        for (i = 0; map[i][0]; i++)
        {
            puts(map[i]);
        }
    }
    return 0;
}