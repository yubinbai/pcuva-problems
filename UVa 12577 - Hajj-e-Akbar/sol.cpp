#include "stdio.h"
int main()
{
    int nt = 1;
    char s[20];
    while (1)
    {
        scanf("%s\n", s);
        switch (s[0])
        {
        case 'H':
            printf("Case %d: Hajj-e-Akbar\n", nt);
            break;
        case 'U':
            printf("Case %d: Hajj-e-Asghar\n", nt);
            break;
        case '*':
            return 0;
        }
        nt++;
    }
    return 0;
}