#include <iostream>
using namespace std ;
int main()
{
    long long int a, b ;
    long long int answer ;
    int T = 0 ;
    cin >> T ;
    for (int i = 1 ; i <= T ; i++)
    {
        cin >> a >> b ;
        if (a % 2 == 1)
        {
            a-- ;
        }
        if (b % 2 == 1)
        {
            b++ ;
        }
        answer = (a + b) * (b - a) / 4 ;
        cout << "Case " << i << ": " << answer << endl ;
    }
    return 0 ;
}