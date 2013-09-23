#include <stdio.h>
#include <ctype.h>
#define MAX_CITIES    100
#define NUM_BINS    5
char bins[MAX_CITIES][NUM_BINS] ;
int diff[MAX_CITIES], city ;
int index(char c)
{
    if (c == 'r')
        return 0 ;
    else if (c == 'o')
        return 1 ;
    else if (c == 'y')
        return 2 ;
    else if (c == 'g')
        return 3 ;
    else if (c == 'b')
        return 4 ;
    else return -1 ;
}
int solve()
{
    int i, j, b, min = 2147483647, mini = 0, d, k ;
    for (i = 0; i < city; i++)
    {
        d = diff[i] ;
        for (j = i + 1; j < city; j++)
        {
            for (k = 0, b = 0; b < NUM_BINS; b++)
            {
                if (bins[i][b] != bins[j][b])
                    k++ ;
            }
            d += k ;
            diff[j] += k ;
        }
        if (d < min)
        {
            min = d ;
            mini = i ;
        }
    }
    for (i = 0; i < city; i++)
        diff[i] = 0 ;
    return mini + 1 ;
}
int main()
{
    char buff[100] ;
    int i, j, indx ;
    city = 0 ;
    while (gets(buff) && buff[0] != '#')
    {
        if (buff[0] == 'e')
        {
            printf("%d\n", solve()) ;
            city = 0 ;
        }
        else
        {
            for (j = 0, i = 0; i < NUM_BINS; i++, j += 4)
                bins[city][index(buff[j])] = buff[j + 2] ;
            city++ ;
        }
    }
    return 0 ;
}
