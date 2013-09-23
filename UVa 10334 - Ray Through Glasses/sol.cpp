#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  F[1005][60];

int main()
{
    F[0][0] = 1; F[1][0] = 2;
    for ( int i = 2 ; i <= 1000 ; ++ i )
    {
        for ( int j = 0 ; j < 55 ; ++ j )
            F[i][j] = F[i - 1][j] + F[i - 2][j];
        for ( int j = 0 ; j < 55 ; ++ j )
        {
            F[i][j + 1] += F[i][j] / 10000;
            F[i][j] %= 10000;
        }
    }

    int n;
    while ( scanf("%d", &n) != EOF )
    {
        int end = 55;
        while ( end > 0 && !F[n][end] )
            --end;
        printf("%d", F[n][end--]);
        while ( end >= 0 )
            printf("%04d", F[n][end--]);
        printf("\n");
    }
    return 0;
}
