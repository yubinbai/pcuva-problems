#include <iostream>
using namespace std ;
#include <cmath>
int main()
{
    double rec[ 11 ][ 8 ] = { 0 } ;
    char type ;
    int n = 0 ;
    double point1_x , point1_y , point2_x , point2_y ;
    while ( cin >> type )
    {
        if ( type == '*' )
        {
            break ;
        }
        n++ ;
        if ( type == 'r' )
        {
            rec[ n ][ 0 ] = 1 ;
            cin >> rec[ n ][ 1 ] >> rec[ n ][ 2 ] >> rec[ n ][ 3 ] >> rec[ n ][ 4 ] ;
        }
        else if ( type == 'c' )
        {
            rec[ n ][ 0 ] = 2 ;
            cin >> rec[ n ][ 1 ] >> rec[ n ][ 2 ] >> rec[ n ][ 3 ] ;
        }
        else if ( type == 't' )
        {
            rec[ n ][ 0 ] = 3 ;
            cin >> point1_x >> point1_y >> point2_x >> point2_y ;
            rec[ n ][ 1 ] = point1_x ;
            rec[ n ][ 2 ] = point1_y ;
            rec[ n ][ 3 ] = point2_x - point1_x ;
            rec[ n ][ 4 ] = point2_y - point1_y ;
            cin >> point2_x >> point2_y ;
            rec[ n ][ 5 ] = point2_x - point1_x ;
            rec[ n ][ 6 ] = point2_y - point1_y ;
            rec[ n ][ 7 ] = rec[ n ][ 3 ] * rec[ n ][ 6 ] - rec[ n ][ 4 ] * rec[ n ][ 5 ] ;
            if ( rec[ n ][ 7 ] == 0 )
            {
                rec[ n ][ 0 ] = 0 ;
            }
        }
    }
    double x , y , temp_x , temp_y ;
    int inside ;
    int counter = 0 ;
    double alpha = 0 , beta = 0 ;
    while ( cin >> x >> y )
    {
        if ( x == 9999.9 && y == 9999.9 )
        {
            break ;
        }
        counter++ ;
        inside = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( rec[ i ][ 0 ] == 1 )
            {
                if ( x > rec[ i ][ 1 ] && x < rec[ i ][ 3 ] && y < rec[ i ][ 2 ] && y > rec[ i ][ 4 ] )
                {
                    inside = 1 ;
                    cout << "Point " << counter << " is contained in figure " << i << endl ;
                }
            }
            else if ( rec[ i ][ 0 ] == 2 )
            {
                if ( ( x - rec[ i ][ 1 ] ) * ( x - rec[ i ][ 1 ] ) + ( y - rec[ i ][ 2 ] ) * ( y - rec[ i ][ 2 ] ) < rec[ i ][ 3 ] * rec[ i ][ 3 ] )
                {
                    inside = 1 ;
                    cout << "Point " << counter << " is contained in figure " << i << endl ;
                }
            }
            else if ( rec[ i ][ 0 ] == 3 )
            {
                temp_x = x - rec[ i ][ 1 ] ;
                temp_y = y - rec[ i ][ 2 ] ;
                if ( ( alpha = ( temp_x * rec[ i ][ 6 ] - temp_y * rec[ i ][ 5 ] ) / rec[ i ][ 7 ] ) > 0
                        && ( beta = ( temp_y * rec[ i ][ 3 ] - temp_x * rec[ i ][ 4 ] ) / rec[ i ][ 7 ] ) > 0
                        && ( alpha + beta ) < 1 )
                {
                    inside = 1 ;
                    cout << "Point " << counter << " is contained in figure " << i << endl ;
                }
            }
        }
        if ( inside == 0 )
        {
            cout << "Point " << counter << " is not contained in any figure" << endl ;
        }
    }
    return 0 ;
}