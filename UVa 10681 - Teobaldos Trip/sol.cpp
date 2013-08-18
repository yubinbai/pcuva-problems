#include <stdio.h>
#include <memory.h>

bool a[ 102 ][ 102 ];
bool b[ 102 ][ 102 ];
bool temp[ 102 ][ 102 ];

int main()
{
    int C, L, S, E, D;
    int u, v;

    while ( scanf("%d %d", &C, &L), C || L )
    {
        memset( a, 0, sizeof a );
        for (int i = 0; i < L; i++)
        {
            scanf("%d %d", &u, &v);
            a[ u - 1 ][ v - 1 ] = a[ v - 1 ][ u - 1 ] = true;
        }

        scanf("%d %d %d", &S, &E, &D);
        memset( b, 0, sizeof b );
        for (int i = 0; i < C; i++) b[i][i] = true;

        while ( D > 0 )
        {
            if ( D & 1 )
            {
                memset( temp, 0, sizeof temp );
                for (int i = 0; i < C; i++)
                    for (int j = 0; j < C; j++)
                        for (int k = 0; k < C; k++)
                            temp[i][j] = temp[i][j] || (b[i][k] && a[k][j]);
                memcpy( b, temp, sizeof temp );
            }

            memset( temp, 0, sizeof temp );
            for (int i = 0; i < C; i++)
                for (int j = 0; j < C; j++)
                    for (int k = 0; k < C; k++)
                        temp[i][j] = temp[i][j] || (a[i][k] && a[k][j]);
            memcpy( a, temp, sizeof temp );

            D >>= 1;
        }

        if ( b[S - 1][E - 1] ) puts("Yes, Teobaldo can travel.");
        else puts("No, Teobaldo can not travel.");
    }

    return 0;
}