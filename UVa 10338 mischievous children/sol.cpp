#include <iostream>
using namespace::std ;
int main()
{
    int datasets ;
    cin >> datasets ;
    int letters[ 26 ] = { 0 } ;
    char input[ 30 ] ;
    int prime[ 9 ] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 } ;
    int factorial[ 9 ] ;
    char dealing ;
    long long int dealing_number ;
    unsigned long int answer ;
    for ( int i = 1 ; i <= datasets ; i++ )
    {
        answer = 1 ;
        for ( int j = 0 ; j < 26 ; j++ )
        {
            letters[ j ] = 0 ;
        }
        for ( int j = 0 ; j < 9 ; j++ )
        {
            factorial[ j ] = 0 ;
        }
        cin >> input ;
        for ( int j = 0 ; ( dealing = input[ j ] ) != '\0' ; j++ )
        {
            dealing_number =  j + 1 ;
            for ( int k = 0 ; k < 9 ; k++ )
            {
                while ( dealing_number % prime[ k ] == 0 )
                {
                    factorial[ k ]++ ;
                    dealing_number /= prime[ k ] ;
                }
            }
            ( letters[ static_cast<int>( dealing ) - static_cast<int>( 'A' ) ] )++ ;
            dealing_number = letters[ static_cast<int>( dealing ) - static_cast<int>( 'A' ) ] ;
            for ( int k = 0 ; k < 9 ; k++ )
            {
                while ( dealing_number % prime[ k ] == 0 )
                {
                    factorial[ k ]-- ;
                    dealing_number /= prime[ k ] ;
                }
            }
        }
        for ( int j = 0 ; j < 9 ; j++ )
        {
            while ( factorial[ j ] > 0 )
            {
                answer *= prime[ j ] ;
                factorial[ j ]-- ;
            }
        }
        cout << "Data set " << i << ": " << answer << endl ;
    }
    return 0 ;
}