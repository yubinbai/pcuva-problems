#include <iostream>
using namespace std ;
int main()
{
    long long int fact[13] ;
    fact[0] = 1 ;
    fact[1] = 1 ;
    for (int i = 2 ; i < 13 ; i++)
    {
        fact[i] = fact[i - 1] * i ;
    }
    int n, k, variables;
    long long int answer ;
    while (cin >> n >> k)
    {
        answer = fact[n] ;
        for (int i = 1 ; i <= k ; i++)
        {
            cin >> variables ;
            if (variables >= 2)
            {
                answer /= fact[variables] ;
            }
        }
        cout << answer << endl ;
    }
    return 0 ;
}