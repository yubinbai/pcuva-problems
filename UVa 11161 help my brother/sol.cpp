#include <iostream>
#include <iomanip>
using namespace std ;
#define Max_n 1500
int
main()
{
    long long digit16 = 100000000 ;
    digit16 *= digit16 ;
    int number_longint[ Max_n + 1 ] = { 0 } ;
    long long *answer[ Max_n + 1 ] ;
    int n = 0 ;
    int i = 0 ;
    int j = 0 ;
    number_longint[ 1 ] = 1 ;
    answer[ 1 ] = new long long [ number_longint[ 1 ] + 1 ] ;
    answer[ 1 ][ 0 ] = 0 ;
    answer[ 1 ][ 1 ] = 0 ;
    number_longint[ 2 ] = 1 ;
    answer[ 2 ] = new long long [ number_longint[ 2 ] + 1 ] ;
    answer[ 2 ][ 0 ] = 0 ;
    answer[ 2 ][ 1 ] = 2 ;
    for ( i = 3 ; i <= Max_n ; i++ )
    {
        if ( answer[ i - 1 ][ number_longint[ i - 1 ] ] >= digit16 / 2 )
        {
            number_longint[ i ] = number_longint[ i - 1 ] + 1 ;
        }
        else
        {
            number_longint[ i ] = number_longint[ i - 1 ] ;
        }
        answer[ i ] = new long long [ number_longint[ i ] + 1 ] ;
        answer[ i ][ 0 ] = 0 ;
        answer[ i ][ 1 ] = answer[ i - 1 ][ 1 ] + answer[ i - 2 ][ 1 ] + 3 ;
        for ( j = 2 ; j <= number_longint[ i - 2 ] ; j++ )
        {
            if ( answer[ i ][ j - 1 ] >= digit16 )
            {
                answer[ i ][ j ] = answer[ i ][ j - 1 ] / digit16 ;
                answer[ i ][ j - 1 ] = answer[ i ][ j - 1 ] % digit16 ;
            }
            else
            {
                answer[ i ][ j ] = 0 ;
            }
            answer[ i ][ j ] += answer[ i - 1 ][ j ] + answer[ i - 2 ][ j ] ;
        }
        for ( j = number_longint[ i - 2 ] + 1 ; j <= number_longint[ i - 1 ] ; j++ )
        {
            if ( answer[ i ][ j - 1 ] >= digit16 )
            {
                answer[ i ][ j ] = answer[ i ][ j - 1 ] / digit16 ;
                answer[ i ][ j - 1 ] = answer[ i ][ j - 1 ] % digit16 ;
            }
            else
            {
                answer[ i ][ j ] = 0 ;
            }
            answer[ i ][ j ] += answer[ i - 1 ][ j ] ;
        }
        for ( j = number_longint[ i - 1 ] + 1 ; j <= number_longint[ i ] ; j++ )
        {
            if ( answer[ i ][ j - 1 ] >= digit16 )
            {
                answer[ i ][ j ] = answer[ i ][ j - 1 ] / digit16 ;
                answer[ i ][ j - 1 ] = answer[ i ][ j - 1 ] % digit16 ;
            }
            else
            {
                answer[ i ][ j ] = 0 ;
            }
        }
    }
    for ( i = 1 ; i <= Max_n ; i++ )
    {
        for ( j = number_longint[ i ] ; j > 1 ; j-- )
        {
            answer[ i ][ j - 1 ] += ( answer[ i ][ j ] & 0x01 ) * digit16 ;
            answer[ i ][ j ] = answer[ i ][ j ] >> 1 ;
        }
        answer[ i ][ 1 ] = answer[ i ][ 1 ] >> 1 ;
    }
    for ( i = 1 ; cin >> n ; i++ )
    {
        if ( n == 0 )
        {
            break ;
        }
        cout << "Set " << i << ":" << endl ;
        j = number_longint[ n ] ;
        while ( answer[ n ][ j ] == 0 && j > 1 )
        {
            j-- ;
        }
        cout << answer[ n ][ j ] ;
        for ( j = j - 1 ; j >= 1 ; j-- )
        {
            cout << setw( 16 ) << setfill('0') << answer[ n ][ j ] ;
        }
        cout << endl ;
    }
    return 0 ;
}