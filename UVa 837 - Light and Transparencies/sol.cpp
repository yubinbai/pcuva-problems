#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct POINT
{
    int x;
    bool end;
    double c;

    bool operator< ( const POINT r ) const
    {
        return x < r.x;
    }
};

int toInt( char *s )
{
    int ret = 0;
    for ( int i = 0; s[ i ]; ++i )
        if ( s[ i ] != '.' )
            ret = ret * 10 + s[ i ] - '0';
    return ret;
}

POINT pt[ 10000 ];

int main()
{

    int t, n;
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d", &n );
        char buf[ 100 ];
        for ( int i = 0; i < n; ++i )
        {
            scanf( "%s", buf );
            int x1 = toInt( buf );

            scanf( "%s", buf );
            scanf( "%s", buf );
            int x2 = toInt( buf );

            scanf( "%s", buf );
            double c;
            scanf( "%lf", &c );

            if ( x1 > x2 )
                swap( x1, x2 );

            pt[ i ].x = x1, pt[ i ].end = 0, pt[ i ].c = c;
            pt[ n + i ].x = x2, pt[ n + i ].end = 1, pt[ n + i ].c = c;
        }
        sort( pt, pt + n * 2 );
        double e = 1;
        int now = pt[ 0 ].x;
        printf( "%d\n", n * 2 + 1 );
        printf( "-inf %.3lf %.3lf\n", ( double )now / 10, e );

        for ( int i = 0; i < n * 2; ++i )
        {
            if ( now != pt[ i ].x )
                printf( "%.3lf %.3lf %.3lf\n", ( double )now / 10, pt[ i ].x / ( double )10, e );

            if ( !pt[ i ].end )
                e *= pt[ i ].c;
            else
                e /= pt[ i ].c;

            now = pt[ i ].x;
        }

        printf( "%.3lf +inf %.3lf\n", ( double )now / 10, e );
        if ( t )
            puts( "" );
    }
    return 0;
}