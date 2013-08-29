#include <stdio.h>
int main ()
{
    char a [150];
    while ( gets (a) )
    {
        int i = 0;
        while ( a [i] != 0 )
        {
            int freq = 0;
            while ( a [i] >= '0' && a [i] <= '9' )
                freq += (a [i++] - '0');
            for ( int j = 0; j < freq; j++ )
            {
                if ( a [i] == 'b' )
                    printf (" ");
                else
                    printf ("%c", a [i]);
            }
            if ( a [i] == '!' )
                printf ("\n");
            i++;
        }
        printf ("\n");
    }
    return 0;
}