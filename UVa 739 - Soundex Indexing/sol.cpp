#include <stdio.h>
#include <string.h>

int soundexcode (char x)
{
    char array1 [] = "AEIOUYWH";
    if ( strchr (array1, x) )
        return 0;

    char array2 [] = "BPFV";
    if ( strchr (array2, x) )
        return 1;

    char array3 [] = "CSKGJQXZ";
    if ( strchr (array3, x) )
        return 2;

    if ( x == 'D' || x == 'T' )
        return 3;

    if ( x == 'L' )
        return 4;

    if ( x == 'M' || x == 'N' )
        return 5;

    if ( x == 'R' )
        return 6;
}

int main ()
{
    printf ("         NAME                     SOUNDEX CODE\n");

    char name [25];

    while ( gets (name) )
    {
        char output [25];
        output [0] = name [0];
        output [1] = output [2] = output [3] = '0';

        int code = soundexcode (name [0]);
        int index = 1;
        int length = strlen (name);

        for ( int i = 1; i < length; i++ )
        {
            int temp_code = soundexcode (name [i]);

            if ( temp_code != code && temp_code != 0 )
                output [index++] = temp_code + '0';

            if ( temp_code != code )
                code = temp_code;
        }

        printf ("%9s%s", "", name);
        for ( int i = 0; i < 25 - length; i++ )
            printf (" ");
        printf ("%c%c%c%c\n", output [0], output [1],
                output [2], output [3]);

    }

    printf ("                   END OF OUTPUT\n");

    return 0;
}