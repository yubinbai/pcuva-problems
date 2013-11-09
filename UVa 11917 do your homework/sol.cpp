#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ )
    {
        int N, D, V;
        string str;
        cin >> N;
        map <string, int> sub;
        map <string, int>::iterator it;
        while ( N-- )
        {
            cin >> str >> V;
            sub[str] = V;
        }
        cin >> D >> str;
        if ( sub.find(str) != sub.end() )
        {
            int time = sub[str];
            if ( time <= D )
                cout << "Case " << t << ": Yesss" << endl;
            else if ( time <= D + 5 )
                cout << "Case " << t << ": Late" << endl;
            else
                cout << "Case " << t << ": Do your own homework!" << endl;
        }
        else
            cout << "Case " << t << ": Do your own homework!" << endl;
    }
    return 0;
}