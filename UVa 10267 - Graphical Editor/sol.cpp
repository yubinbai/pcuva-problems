#include <stdio.h>
#define MAX 250
#define OFFSET 1
#define DOS_NAME 12
int n, m;
int fillRectangle(int m_ini, int n_ini, int m_end, int n_end, char color, char pTable[][MAX + OFFSET])
{
    int i, j;
    for (i = n_ini; i <= n_end; i++)
    {
        for (j = m_ini; j <= m_end; j++)
        {
            pTable[i][j] = color;
        }
    }
    return 0;
}
int fillRegion(int x, int y, char oldColor, char newColor, char pTable[][MAX + OFFSET])
{
    pTable[y][x] = newColor;
    if ((pTable[y][x - 1] == oldColor) && (x > OFFSET))
    {
        fillRegion(x - 1, y, oldColor, newColor, pTable);
    }
    if ((pTable[y][x + 1] == oldColor) && (x < m))
    {
        fillRegion(x + 1, y, oldColor, newColor, pTable);
    }
    if ((pTable[y - 1][x] == oldColor) && (y > OFFSET))
    {
        fillRegion(x, y - 1, oldColor, newColor, pTable);
    }
    if ((pTable[y + 1][x] == oldColor) && (y < n))
    {
        fillRegion(x, y + 1, oldColor, newColor, pTable);
    }
    return 0;
}
int printImage(int m, int n, char pTable[][MAX + OFFSET])
{
    int i, j;
    for (i = OFFSET; i < n + OFFSET; i++)
    {
        for (j = OFFSET; j < m + OFFSET; j++ )
        {
            printf("%c", pTable[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int main (int argc, const char *argv[])
{
    char image[MAX + OFFSET][MAX + OFFSET];
    char command;
    int x1, x2, y1, y2, tmp;
    char color, oldColor;
    char filename[DOS_NAME + 1];
    while (scanf("%c", &command) != EOF)
    {
        if (command == 'X')
        {
            return 0;
        }
        switch (command)
        {
        case 'I' :
            scanf("%d %d", &m, &n);
            fillRectangle(1, 1, m, n, 'O', image);
            break;
        case 'C' :
            fillRectangle(1, 1, m, n, 'O', image);
            break;
        case 'L' :
            scanf("%d %d %c", &x1, &y1, &color);
            image[y1][x1] = color;
            break;
        case 'V' :
            scanf("%d %d %d %c", &x1, &y1, &y2, &color);
            if (y2 >= y1)
                fillRectangle(x1, y1, x1, y2, color, image);
            else
                fillRectangle(x1, y2, x1, y1, color, image);
            break;
        case 'H' :
            scanf("%d %d %d %c", &x1, &x2, &y1, &color);
            if (x2 >= x1)
                fillRectangle(x1, y1, x2, y1, color, image);
            else
                fillRectangle(x2, y1, x1, y1, color, image);
            break;
        case 'K' :
            scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
            if (x1 >= x2)
            {
                tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            if (y1 >= y2)
            {
                tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            fillRectangle(x1, y1, x2, y2, color, image);
            break;
        case 'F' :
            scanf("%d %d %c", &x1, &y1, &color);
            oldColor = image[y1][x1];
            if (oldColor != color)
            {
                fillRegion(x1, y1, oldColor, color, image);
            }
            break;
        case 'S' :
            scanf("%s", &filename);
            printf("%s\n", filename);
            printImage(m, n, image);
            break;
        default:
            break;
        }
    }
    return 0;
}
