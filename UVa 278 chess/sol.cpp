#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f( char t, int n, int m )
{
    if ( n < m ) return f( t, m, n );
    if ( t == 'r' || t == 'Q' ) return m;
    if ( t == 'K' ) return (n + 1) / 2 * (m + 1) / 2;
    if ( m == 1 ) return n;
    if ( m == 2 ) return n / 4 * 4 + (n % 4 < 3 ? n % 4 : 2) * 2;
    return (n * m + 1) / 2;
}

int main()
{
    int  n, m, c;
    char t;
    while ( scanf("%d", &c) != EOF )
    {
        getchar();
        while ( c -- )
        {
            scanf("%c %d %d", &t, &n, &m);
            getchar();
            printf("%d\n", f(t, n, m));
        }
    }
    return 0;
}