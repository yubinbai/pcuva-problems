#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
int main()
{
    long long int x = 0 ;
    long long int y = 0 ;
    long long int n = 0 ;
    while ( cin >> n )
    {
        if ( n == 0 )
            break ;
        x = 1 ;
        while ( x * x * x < n )
            x++ ;
        y = 0 ;
        while ( x * x * x - y * y * y != n )
        {
            while ( x * x * x - y * y * y > n )
                y++ ;
            while ( x * x * x - y * y * y < n )
                x++ ;
            if ( x == y + 1 )
                break ;
        }
        if ( x * x * x - y * y * y != n )
            cout << "No solution" << endl ;
        else
            cout << x << " " << y << endl ;
    }
    return 0 ;
}