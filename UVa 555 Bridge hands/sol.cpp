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
struct decks
{
    char suit;
    char card;
} a [4] [15];
bool cmp (decks p, decks q)
{
    if ( p.suit == 'C' ) p.suit = 'a';
    else if ( p.suit == 'D' ) p.suit = 'b';
    else if ( p.suit == 'S' ) p.suit = 'c';
    else if ( p.suit == 'H' ) p.suit = 'd';
    if ( q.suit == 'C' ) q.suit = 'a';
    else if ( q.suit == 'D' ) q.suit = 'b';
    else if ( q.suit == 'S' ) q.suit = 'c';
    else if ( q.suit == 'H' ) q.suit = 'd';
    if ( p.card == '2' ) p.card = 'a';
    else if ( p.card == '3' ) p.card = 'b';
    else if ( p.card == '4' ) p.card = 'c';
    else if ( p.card == '5' ) p.card = 'd';
    else if ( p.card == '6' ) p.card = 'e';
    else if ( p.card == '7' ) p.card = 'f';
    else if ( p.card == '8' ) p.card = 'g';
    else if ( p.card == '9' ) p.card = 'h';
    else if ( p.card == 'T' ) p.card = 'i';
    else if ( p.card == 'J' ) p.card = 'j';
    else if ( p.card == 'Q' ) p.card = 'k';
    else if ( p.card == 'K' ) p.card = 'l';
    else if ( p.card == 'A' ) p.card = 'm';
    if ( q.card == '2' ) q.card = 'a';
    else if ( q.card == '3' ) q.card = 'b';
    else if ( q.card == '4' ) q.card = 'c';
    else if ( q.card == '5' ) q.card = 'd';
    else if ( q.card == '6' ) q.card = 'e';
    else if ( q.card == '7' ) q.card = 'f';
    else if ( q.card == '8' ) q.card = 'g';
    else if ( q.card == '9' ) q.card = 'h';
    else if ( q.card == 'T' ) q.card = 'i';
    else if ( q.card == 'J' ) q.card = 'j';
    else if ( q.card == 'Q' ) q.card = 'k';
    else if ( q.card == 'K' ) q.card = 'l';
    else if ( q.card == 'A' ) q.card = 'm';
    if ( p.suit < q.suit ) return true;
    if ( p.suit == q.suit && p.card < q.card ) return true;
    return false;
}
int main ()
{
    char start [5];
    while ( scanf ("%s", &start) && start [0] != '#' )
    {
        char input [100];
        scanf ("%s", input);
        int index;
        if ( start [0] == 'S' ) index = 0;
        else if ( start [0] == 'W' ) index = 1;
        else if ( start [0] == 'N' ) index = 2;
        else index = 3;
        int len = strlen (input);
        int col = 0;
        int cnt = 0;
        for ( int i = 0; i < len; i += 2 )
        {
            index++;
            index %= 4;
            a [index] [col].suit = input [i];
            a [index] [col].card = input [i + 1];
            cnt++;
            if ( cnt == 4 )
            {
                cnt = 0;
                col++;
            }
        }
        scanf ("%s", input);
        len = strlen (input);
        for ( int i = 0; i < len; i += 2 )
        {
            index++;
            index %= 4;
            a [index] [col].suit = input [i];
            a [index] [col].card = input [i + 1];
            cnt++;
            if ( cnt == 4 )
            {
                cnt = 0;
                col++;
            }
        }
        for ( int i = 0; i < 4; i++ )
        {
            for ( int j = 0; j < 13; j++ )
            {
                for ( int k = j + 1; k < 13; k++ )
                {
                    if ( !cmp (a [i] [j], a [i] [k]) ) swap (a [i] [j], a [i] [k]);
                }
            }
        }
        printf ("S:");
        for ( int i = 0; i < 13; i++ )
            printf (" %c%c", a [0] [i].suit, a [0] [i].card);
        printf ("\nW:");
        for ( int i = 0; i < 13; i++ )
            printf (" %c%c", a [1] [i].suit, a [1] [i].card);
        printf ("\nN:");
        for ( int i = 0; i < 13; i++ )
            printf (" %c%c", a [2] [i].suit, a [2] [i].card);
        printf ("\nE:");
        for ( int i = 0; i < 13; i++ )
            printf (" %c%c", a [3] [i].suit, a [3] [i].card);
        printf ("\n");
    }
    return 0;
}
