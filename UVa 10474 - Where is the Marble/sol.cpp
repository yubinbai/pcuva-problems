#include <stdio.h>
#include <memory.h>

int acc[ 10004 ];
int pos[ 10004 ];

int main()
{
    int n, q;
    int a;
    int caso = 1;

    while ( scanf("%d %d", &n, &q), n || q )
    {
        memset( acc, 0, sizeof acc );
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            acc[ a ]++;
        }
        memset( pos, -1, sizeof pos );
        if ( acc[0] > 0 ) pos[ 0 ] = 0;
        for (int i = 1; i <= 10000; i++)
        {
            if ( acc[ i ] > 0 ) pos[ i ] = acc[ i - 1 ];
            acc[ i ] += acc[ i - 1 ];
        }
        printf("CASE# %d:\n", caso++);
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &a);
            if ( pos[a] == -1 ) printf("%d not found\n", a);
            else printf("%d found at %d\n", a, pos[a] + 1);
        }
    }

    return 0;
}