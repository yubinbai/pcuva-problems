#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;
int shuffles [100 + 5] [52 + 3];
map <int, string> cardName;
void reset ()
{
    string suit [] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    string value [] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    int cardNum = 1;
    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; j < 13; j++ )
            cardName [cardNum++] = value [j] + " of " + suit [i];
    }
}
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    bool blank = false;
    reset ();
    while ( testCase-- )
    {
        int n;
        scanf ("%d", &n);
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= 52; j++ ) scanf ("%d", &shuffles [i] [j]);
        }
        getchar ();
        int present [52 + 3];
        for ( int i = 1; i <= 52; i++ ) present [i] = i;
        char input [50];
        while ( gets (input) && strlen (input) )
        {
            int num = atoi (input);
            int next [52 + 3];
            for ( int i = 1; i <= 52; i++ )
                next [i] = present [shuffles [num] [i]];
            for ( int i = 1; i <= 52; i++ ) present [i] = next [i];
        }
        if ( blank ) printf ("\n");
        blank = true;
        for ( int i = 1; i <= 52; i++ )
            cout << cardName [present [i]] << endl;
    }
    return 0;
}