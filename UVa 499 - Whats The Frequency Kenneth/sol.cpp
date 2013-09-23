#include <stdio.h>
int chars[53];
int count;
void inc(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        chars[ch - 'a' + 27]++;
    else if (ch >= 'A' && ch <= 'Z')
        chars[ch - 'A' + 1]++;
}
void print()
{
    int i, max;
    max = 0;
    for (i = 1; i <= 52; i++)
        if (chars[i] > max) max = chars[i];
    for (i = 1; i <= 52; i++)
        if (chars[i] == max)
        {
            if (i <= 26)
                printf("%c", i - 1 + 'A');
            else printf("%c", i - 27 + 'a');
        }
    printf(" %d\n", max);
    for (i = 1; i <= 52; i++)
        chars[i] = 0;
    count = 0;
}

int main()
{
    char ch;
    int i;
    count = 0;
    for (i = 1; i <= 52; i++)
        chars[i] = 0;
    while (1 == scanf("%c", &ch))
    {
        if (ch == '\n')
        {
            print();
        }
        else
        {
            inc(ch);
            count++;
        }
    }
    return 0;
}