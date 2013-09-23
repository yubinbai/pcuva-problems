#include <iostream>
using namespace std;
#include <cstring>
int alpha_to_number( char character )
{
    return (int)character - (int)('0');
}
char number_to_alpha( int number )
{
    return '0' + number;
}
int main()
{
    int cases, i, j, number, carry;
    char *number_1 = new char [ 220 ];
    char *number_2 = new char [ 220 ];
    char *temp, *print;
    cin >> cases;
    for ( i = 1; i <= cases; i++ )
    {
        cin >> number_1 >> number_2;
        if ( strlen( number_1 ) < strlen( number_2 ) )
        {
            // Do a swap job.
            temp = number_1;
            number_1 = number_2;
            number_2 = temp;
        }
        carry = 0;
        for ( j = 1; j <= strlen( number_2 ); j++ )
        {
            number = alpha_to_number( number_1[ j - 1 ] ) + alpha_to_number( number_2[ j - 1 ] ) + carry;
            carry = number / 10;
            number = number % 10;
            number_1[ j - 1 ] = number_to_alpha( number );
        }
        for (; j <= strlen( number_1 ); j++ )
        {
            number = alpha_to_number( number_1[ j - 1 ] ) + carry;
            carry = number / 10;
            number = number % 10;
            number_1[ j - 1 ] = number_to_alpha( number );
        }
        print = number_1;
        while ( *print == '0' )
        {
            print ++;
        }
        cout << print;
        if ( carry != 0 )
        {
            cout << carry;
        }
        cout << endl;
    }
    return 0;
}