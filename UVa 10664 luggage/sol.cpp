#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std ;
const int MaxSum = 200 ;
int main()
{
    bitset < MaxSum + 1 > b ;
    string buffer ;
    istringstream os ;
    int luggage = 0 ;
    int sum = 0 ;
    int casenum = 0 ;
    int i = 0 ;
    cin >> casenum ;
    getline( cin, buffer ) ; // absorb end of line
    for ( i = 1 ; i <= casenum ; i++ )
    {
        getline( cin, buffer ) ;
        os.clear() ;
        os.str( buffer ) ;
        sum = 0 ;
        b.reset() ;
        b[ 0 ] = 1 ;
        while ( os >> luggage )
        {
            sum += luggage ;
            b |= b << luggage ;
        }
        if ( sum % 2 == 0 && b[ sum / 2 ] == 1 )
        {
            cout << "YES" << endl ;
        }
        else
        {
            cout << "NO" << endl ;
        }
    }
    return 0 ;
}