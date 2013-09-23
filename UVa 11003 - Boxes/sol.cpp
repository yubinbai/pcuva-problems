#include <iostream>
#include <algorithm>
using namespace std ;
#define MaxN 1000
#define MaxLoad 3000
#define MaxWeight 3000
int main()
{
    int boxs[ MaxLoad + MaxWeight + 1 ] = { 0 } ;
    int weight[ MaxN ] = { 0 } ;
    int load[ MaxN ] = { 0 } ;
    int n = 0 ;
    int i = 0 ;
    int j = 0 ;
    while ( cin >> n && n != 0 )
    {
        for ( i = 0 ; i < n ; i++ )
        {
            cin >> weight[ i ] >> load[ i ] ;
        }
        fill( boxs, boxs + MaxLoad + MaxWeight + 1, 0 ) ;
        for ( i = n - 1 ; i >= 0 ; i-- )
        {
            for ( j = load[ i ] ; j >= 0 ; j-- )
            {
                if ( boxs[ j ] > 0 )
                {
                    boxs[ j + weight[ i ] ] = max( boxs[ j + weight[ i ] ], boxs[ j ] + 1 ) ;
                }
            }
            boxs[ weight[ i ] ] = max( boxs[ weight[ i ] ], 1 ) ;
        }
        cout << *( max_element(boxs, boxs + MaxLoad + MaxWeight + 1) ) << endl ;
    }
    return 0 ;
}
