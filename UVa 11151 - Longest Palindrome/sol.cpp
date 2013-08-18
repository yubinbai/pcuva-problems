#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[ 1005 ];
char revstr[ 1005 ];
int  f[ 1005 ][ 1005 ];

int main()
{
    int T;
    while ( scanf("%d", &T) != EOF )
    {
        getchar();
        for ( int t = 1 ; t <= T ; ++ t )
        {
            gets(string);
            int len = strlen(string);
            for ( int i = 0 ; i < len ; ++ i )
                revstr[len - i - 1] = string[i];

            memset( f, 0, sizeof(f) );
            for ( int i = 1 ; i <= len ; ++ i )
                for ( int j = 1 ; j <= len ; ++ j )
                    if ( string[i - 1] == revstr[j - 1] )
                        f[i][j] = f[i - 1][j - 1] + 1;
                    else
                    {
                        f[i][j] = f[i - 1][j];
                        if ( f[i][j] < f[i][j - 1] )
                            f[i][j] = f[i][j - 1];
                    }
            printf("%d\n", f[len][len]);
        }
    }
    return 0;
}
