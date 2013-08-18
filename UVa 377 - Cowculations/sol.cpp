/* 377 - Cowculations */
#include <stdio.h>
#include <string.h>
int
str2num(char *s)
{
    int i;
    int num = 0;
    for (i = 0; i < strlen(s); i++)
    {
        num *= 4;
        if (s[i] == 'U')
        {
            num++;
        }
        else if (s[i] == 'C')
        {
            num += 2;
        }
        else if (s[i] == 'D')
        {
            num += 3;
        }
    }
    return num;
}
int main(void)
{
    int i, j;
    int n;
    int n1, n2;
    char buf[1024];
    scanf("%d", &n);
    printf("COWCULATIONS OUTPUT\n");
    for (i = 0; i < n; i++)
    {
        scanf(" %s", buf);
        n1 = str2num(buf);
        scanf(" %s", buf);
        n2 = str2num(buf);
        for (j = 0; j < 3; j++)
        {
            char c;
            scanf(" %c", &c);
            if (c == 'A')
            {
                n2 += n1;
            }
            else if (c == 'R')
            {
                n2 /= 4;
            }
            else if (c == 'L')
            {
                n2 *= 4;
            }
        }
        scanf(" %s", buf);
        n1 = str2num(buf);
        if (n1 == n2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}