#include <iostream>
#include <iomanip>
#include <algorithm>
#define MaxN 10
using namespace std ;
int matrix[ MaxN + 1 ][ 2 ] = { 0 } ;
long long int mult[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
int separate[ MaxN + 1 ][ MaxN + 1 ] = { 0 } ;
void printMatrixSeq( int a, int b, int separate[][ MaxN + 1 ] )
{
    if ( a == b )
    {
        cout << "A" << a ;
    }
    else
    {
        cout << "(" ;
        printMatrixSeq( a, a + separate[ a ][ b ] - 1, separate ) ;
        cout << " x " ;
        printMatrixSeq( a + separate[ a ][ b ], b, separate ) ;
        cout << ")" ;
    }
}
void print( int N )
{
    int i = 0 ; // loop counter
    int j = 0 ; // loop counter
    for ( i = 1 ; i <= N ; i++ )
    {
        for ( j = 1 ; j <= N - i + 1 ; j++ )
        {
            cout << separate[ j ][ j + i - 1 ] << "\t" ;
        }
        cout << endl ;
    }
    for ( i = 1 ; i <= N ; i++ )
    {
        for ( j = 1 ; j <= N - i + 1 ; j++ )
        {
            cout << mult[ j ][ j + i - 1 ] << "\t" ;
        }
        cout << endl ;
    }
}
int
main()
{
    int cases = 0 ;
    int N = 0 ;
    long long int temp = 0 ;
    int i = 0 ; // loop counter
    int j = 0 ; // loop counter
    int k = 0 ; // loop counter
    for ( i = 1 ; i <= MaxN ; i++ )
    {
        mult[ i ][ i ] = 0 ;
        separate[ i ][ i ] = 1 ;
    }
    while ( cin >> N )
    {
        if ( N == 0 )
        {
            break ;
        }
        cases++ ;
        for ( i = 1 ; i <= N ; i++ )
        {
            cin >> matrix[ i ][ 0 ] >> matrix[ i ][ 1 ] ;
        }
        // calculate multiplication needed for continue i matrixes.
        for ( i = 2 ; i <= N ; i++ )
        {
            for ( j = 1 ; j <= N - i + 1 ; j++ )
            {
                mult[ j ][ j + i - 1 ] =  matrix[ j ][ 0 ] * matrix[ j + 1 ][ 0 ] *
                                          matrix[ j + i - 1 ][ 1 ] +
                                          mult[ j + 1 ][ j + i - 1 ] ;
                separate[ j ][ j + i - 1 ] = 1 ;
                for ( k = 2 ; k <= i - 1 ; k++ )
                {
                    temp =  matrix[ j ][ 0 ] * matrix[ j + k ][ 0 ] *
                            matrix[ j + i - 1 ][ 1 ] +
                            mult[ j ][ j + k - 1 ] +
                            mult[ j + k ][ j + i - 1 ] ;
                    if ( temp < mult[ j ][ j + i - 1 ] )
                    {
                        separate[ j ][ j + i - 1 ] = k ;
                        mult[ j ][ j + i - 1 ] = temp ;
                    }
                }
            }
        }
        cout << "Case " << cases << ": " ;
        printMatrixSeq( 1, N, separate ) ;
        cout << endl ;
    }
    return 0 ;
}