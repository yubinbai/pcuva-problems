#include <iostream>
using namespace std ;
int main()
{
    int N , input , i ;
    bool had_positive ;
    while ( cin >> N )
    {
        if ( N == 0 )
        {
            break ;
        }
        had_positive = 0 ;
        for ( i = 1 ; i <= N ; i++ )
        {
            cin >> input ;
            if ( input > 0 )
            {
                cout << input ;
                break ;
            }
        }
        if ( i > N )
        {
            cout << "0" ;
        }
        else
        {
            for ( i = i + 1 ; i <= N ; i++ )
            {
                cin >> input ;
                if ( input > 0 )
                {
                    cout << " " << input ;
                }
            }
        }
        cout << endl ;
    }
    return 0 ;
}