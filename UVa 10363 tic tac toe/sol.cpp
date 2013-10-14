#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        string S[3];
        cin >> S[0] >> S[1] >> S[2];
        int xWin = 0, yWin = 0;
        int X = 0, Y = 0;
        int i, j;
        if ( S[0][0] == 'X' && S[1][1] == 'X' && S[2][2] == 'X' )  xWin++;
        if ( S[2][0] == 'X' && S[1][1] == 'X' && S[0][2] == 'X' )  xWin++;
        if ( S[0][0] == 'X' && S[1][0] == 'X' && S[2][0] == 'X' )  xWin++;
        if ( S[0][1] == 'X' && S[1][1] == 'X' && S[2][1] == 'X' )  xWin++;
        if ( S[0][2] == 'X' && S[1][2] == 'X' && S[2][2] == 'X' )  xWin++;
        if ( S[0][0] == 'X' && S[0][1] == 'X' && S[0][2] == 'X' )  xWin++;
        if ( S[1][0] == 'X' && S[1][1] == 'X' && S[1][2] == 'X' )  xWin++;
        if ( S[2][0] == 'X' && S[2][1] == 'X' && S[2][2] == 'X' )  xWin++;
        if ( S[0][0] == 'O' && S[1][1] == 'O' && S[2][2] == 'O' )  yWin++;
        if ( S[2][0] == 'O' && S[1][1] == 'O' && S[0][2] == 'O' )  yWin++;
        if ( S[0][0] == 'O' && S[1][0] == 'O' && S[2][0] == 'O' )  yWin++;
        if ( S[0][1] == 'O' && S[1][1] == 'O' && S[2][1] == 'O' )  yWin++;
        if ( S[0][2] == 'O' && S[1][2] == 'O' && S[2][2] == 'O' )  yWin++;
        if ( S[0][0] == 'O' && S[0][1] == 'O' && S[0][2] == 'O' )  yWin++;
        if ( S[1][0] == 'O' && S[1][1] == 'O' && S[1][2] == 'O' )  yWin++;
        if ( S[2][0] == 'O' && S[2][1] == 'O' && S[2][2] == 'O' )  yWin++;
        FOI(i, 0, 2)
        {
            FOI(j , 0, 2)
            {
                if ( S[i][j] == 'O' )
                    Y++;
                if ( S[i][j] == 'X' )
                    X++;
            }
        }
        bool flag = true;
        if ( xWin > 0 && yWin > 0 )
            goto no;
        if ( xWin > 0 && Y + 1 == X )
            goto yes;
        if ( xWin > 0 && Y + 1 != X )
            goto no;
        if ( yWin > 0 && X == Y )
            goto yes;
        if ( yWin > 0 && X != Y )
            goto no;
        if ( X == Y || X == Y + 1 )
            goto yes;
        else
            goto no;
yes:    cout << "yes";
        goto end;
no:     cout << "no";
        goto end;
end:    cout << endl;
    }
    return 0;
}