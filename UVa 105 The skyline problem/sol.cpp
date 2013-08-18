#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int H[ 10005 ] = {0};

int main()
{
    int l, h, r;
    while ( scanf("%d%d%d", &l, &h, &r) != EOF )
        for ( int i = l ; i <= r ; ++ i )
            H[i] = H[i] > h ? H[i] : h;

    int s = 0, e = 0;
    while ( !H[s] ) s ++;
    printf("%d %d", s, H[s]);
    for ( int i = s + 1 ; i <= 10001 ; ++ i )
        if ( H[i] != H[i - 1] )
        {
            if ( H[i - 1] < H[i] )
                printf(" %d %d", i, H[i]);
            else
                printf(" %d %d", i - 1, H[i]);
        }
    printf("\n");
    return 0;
}
