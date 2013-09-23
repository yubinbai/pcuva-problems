#include <iostream>
using namespace std ;
#include <iomanip>
int main()
{
    int **prime = new int *[ 54 ] ;
    prime[ 1 ] = new int [ 2 ] ;
    prime[ 1 ][ 0 ] = 2 ;
    prime[ 1 ][ 1 ] = 4 ;
    prime[ 2 ] = new int [ 1 ] ;
    prime[ 2 ][ 0 ] = 3 ;
    prime[ 2 ][ 1 ] = 9 ;
    int largest_prime_number = 2 ;
    for ( int i = 3 ; i < 54 ; i++ )
    {
        for ( int j = prime[ i - 1 ][ 0 ] + 2 ;  ; j = j + 2 )
        {
            int k ;
            for ( k = 1 ; prime[ k ][ 1 ] < j ; k++ )
            {
                if ( j % prime[ k ][ 0 ] == 0 )
                {
                    break ;
                }
            }
            if ( prime[ k ][ 1 ] > j )
            {
                prime[ i ] = new int [ 2 ] ;
                prime[ i ][ 0 ] = j ;
                prime[ i ][ 1 ] = j * j ;
                break ;
            }
        }
    }
    long long int input , dealing_input , input_multi2 , sum_progression ;
    int progression ;
    cout << "PERFECTION OUTPUT" << endl ;
    while ( cin >> input )
    {
        if ( input == 0 )
        {
            break ;
        }
        dealing_input = input ;
        input_multi2 = input * 2 ;
        sum_progression = 1 ;
        for ( int i = 1 ; dealing_input != 1 ; i++ )
        {
            progression = 1 ;
            while ( dealing_input % prime[ i ][ 0 ] == 0 )
            {
                progression = progression * prime[ i ][ 0 ] + 1 ;
                dealing_input /= prime[ i ][ 0 ] ;
            }
            sum_progression *= progression ;
            if ( sum_progression > input_multi2 )
            {
                break ;
            }
        }
        if ( sum_progression > input_multi2 )
        {
            cout << setw( 5 ) << input << "  " << "ABUNDANT" << endl ;
        }
        else if ( sum_progression < input_multi2 )
        {
            cout << setw( 5 ) << input << "  " << "DEFICIENT" << endl ;
        }
        else
        {
            cout << setw( 5 ) << input << "  " << "PERFECT" << endl ;
        }
    }
    cout << "END OF OUTPUT" << endl ;
    return 0 ;
}