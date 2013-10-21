#include <iostream>
#include <cctype>
#include <cstring>
#include <map>
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define MAX        2500
bool prime[MAX + 1];
void Seive()
{
    memset(prime, true, sizeof prime);
    prime[0] = false; prime[1] = false;
    int i, j;
    FOI(i, 2, MAX)
    for (j = 2 * i; j <= MAX; j += i)
        prime[j] = false;
}
int main()
{
    Seive();
    int T, t;
    cin >> T;
    FOI(t, 1, T)
    {
        map<char, int> Map;
        map<char, int>::iterator it;
        int i, j;
        string str;
        cin >> str;
        int L = str.length() - 1;
        FOI(i, 0, L)
        Map[str[i]]++;
        bool flag = false;
        cout << "Case " << t << ": ";
        for ( it = Map.begin(); it != Map.end(); it++ )
        {
            if ( prime[(*it).second] )
            {
                flag = true;
                cout << (*it).first;
            }
        }
        if ( !flag )
            cout << "empty";
        cout << endl;
    }
    return 0;
}