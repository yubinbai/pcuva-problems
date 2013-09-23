#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, val, i = 1;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        int treat = 0, party = 0;
        while (n--)
        {
            scanf("%d", &val);
            if (val == 0)
            {
                treat++;
            }
            else
            {
                party++;
            }
        }
        printf("Case %d: %d\n", i, (party - treat));
        i++;
    }
    return 0;
}
