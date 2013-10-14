#include <stdio.h>
char s[1000005];
int main()
{
    int len, i;
    gets(s);
    while (s[0] != '.' || s[1])
    {
        len = 1;
        for (i = 1; s[i]; i++)
            while (s[i] != s[i % len])
                len++;
        if (i % len == 0)
            printf("%d\n", i / len);
        else
            puts("1");
        gets(s);
    }
    return 0;
}