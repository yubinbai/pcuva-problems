#include <iostream>
#include <cmath>
using namespace std ;
long long int n = 0 ;
long long int cal( long long int a )
{
    return ( a * a - 3 * a - 2 * n ) ;
}
int main()
{
    long long int left = 0 ;
    long long int right = 0 ;
    int caseNum = 0 ;
    while ( cin >> n && n != 0 )
    {
        caseNum++ ;
        left = 0 ;
        right = 99999999 ;
        while ( right - left > 1 )
        {
            if ( cal( (right + left) / 2 ) >= 0 )
                right = (right + left) / 2 ;
            else
                left = (right + left) / 2 ;
        }
        cout << "Case " << caseNum << ": " << right << endl ;
    }
    return 0 ;
}
