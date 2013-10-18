#include <iostream>
#include "string.h"
using namespace std ;
int hexadecimal_to_decimal( char character )
{
    int answer = (int)character - (int)('0') ;
    if ( answer >= 0 && answer <= 9 )
    {
        return answer ;
    }
    else
    {
        return (int)character - (int)('A') + 10 ;
    }
}
char decimal_to_hexadecimal( int number )
{
    if ( number >= 10 )
    {
        return 'A' + number - 10 ;
    }
    else
    {
        return '0' + number ;
    }
}
void reverse_string( char *front, char *last )
{
    if ( front < last )
    {
        char temp = *front ;
        *front = *last ;
        *last = temp ;
        reverse_string( front + 1, last - 1 ) ;
    }
}
void my_itoa( int number , char *buffer , int base )
{
    if ( number == 0 )
    {
        buffer[ 0 ] = '0' ;
        buffer[ 1 ] = '\0' ;
    }
    else
    {
        int answer = 0 ;
        int i = 0 ;
        while ( number != 0 )
        {
            buffer[ i ] = decimal_to_hexadecimal( number % base ) ;
            number /= base ;
            i++ ;
        }
        buffer[ i ] = '\0' ;
        reverse_string( buffer, buffer + i - 1 ) ;
    }
}
int main()
{
    int number, answer, i;
    char buffer[ 12 ], temp ;
    while ( cin >> number )
    {
        if ( number < 0 )
        {
            break ;
        }
        if ( number == 0 )
        {
            cin.get( temp );
            if ( temp == 'x' )
            {
                answer = 0 ;
                cin >> buffer ;
                for ( i = 0 ; i < strlen( buffer ) ; i++ )
                {
                    answer = answer * 16 + hexadecimal_to_decimal( buffer[ i ] ) ;
                }
                cout << answer << endl ;
            }
            else
            {
                my_itoa( number, buffer, 16 ) ;
                cout << "0x" << buffer << endl ;
            }
        }
        else
        {
            my_itoa( number, buffer, 16 ) ;
            cout << "0x" << buffer << endl ;
        }
    }
    return 0 ;
}