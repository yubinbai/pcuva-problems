#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue< int > Q[2];

int main()
{
    int test;
    int Len, M;
    int cent;
    string side;

    cin >> test;
    while ( test-- )
    {
        cin >> Len >> M;
        Len *= 100;
        for (int i = 0; i < M; i++)
        {
            cin >> cent >> side;
            if ( side == "left" ) Q[0].push( cent );
            else Q[1].push( cent );
        }
        int ans = 0;
        int actualSide = 0;
        while ( !Q[0].empty() || !Q[1].empty() )
        {
            int freeLen = Len;
            while ( !Q[actualSide].empty() && freeLen >= Q[actualSide].front() )
            {
                freeLen -= Q[actualSide].front();
                Q[actualSide].pop();
            }
            ans++;
            actualSide = (actualSide + 1) % 2;
        }
        cout << ans << endl;
    }

    return 0;
}