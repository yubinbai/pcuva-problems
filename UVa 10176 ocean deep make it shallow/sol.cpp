#include <stdio.h>
char *res[2] = {"NO", "YES"};
int main()
{
    register int p = 131071, mod = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '#')
        {
            puts(res[!mod]);
            mod = 0;
        }
        else if (c != '\n')
            mod = (mod * 2 + c - '0') % p;
    }
    return 0;
}