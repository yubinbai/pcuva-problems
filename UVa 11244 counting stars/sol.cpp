#include<cstdio>
#include<cstring>
char sky[102][102], i, j;
unsigned int X, Y, stars;
bool isstar(char a, char b)
{
    if (sky[a - 1][b - 1] == '*') return 0;
    if (sky[a][b - 1] == '*') return 0;
    if (sky[a + 1][b - 1] == '*') return 0;
    if (sky[a + 1][b] == '*') return 0;
    if (sky[a + 1][b + 1] == '*') return 0;
    if (sky[a][b + 1] == '*') return 0;
    if (sky[a - 1][b + 1] == '*') return 0;
    if (sky[a - 1][b] == '*') return 0;
    return 1;
}
int main(void)
{
    for (i = 0; i < 102; i++)
        sky[i][0] = sky[0][i] = '_';
    while (scanf("%u %u\n", &X, &Y) && X)
    {
        for (i = 0; i != X; i++)
            gets(sky[i + 1] + 1);
        for (i = 0; i <= X + 1; i++) sky[i][Y + 1] = '_';
        for (j = 0; j <= Y + 1; j++) sky[X + 1][j] = '_';
        X++; Y++; stars = 0;
        for (i = 1; i != X; i++)
            for (j = 1; j != Y; j++)
                if (sky[i][j] == '*' && isstar(i, j)) stars++;
        printf("%u\n", stars);
    }
    return 0;
}