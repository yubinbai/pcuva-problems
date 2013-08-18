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
#include <bitset>
#include <utility>
#include <set>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

struct teams
{
    int teamNumber;
    int solved [9 + 3];
    int penalty [9 + 3];
    bool submit;
} a [100 + 5];

void reset ()
{
    for ( int i = 0; i < 105; i++ )
    {
        a [i].teamNumber = i;
        memset (a [i].solved, 0, sizeof (a [i].solved));
        memset (a [i].penalty, 0, sizeof (a [i].penalty));
        a [i].submit = false;
    }
}

void calculateAll ()
{
    for ( int i = 1; i < 105; i++ )
    {
        for ( int j = 1; j <= 9; j++ )
        {
            if ( a [i].solved [j] )
            {
                a [i].solved [10]++;
                a [i].penalty [10] += a [i].penalty [j];
            }
        }
    }
}

bool cmp (teams x, teams y)
{
    if ( x.solved [10] > y.solved [10] ) return true;
    if ( x.solved [10] == y.solved [10] && x.penalty [10] < y.penalty [10] ) return true;
    if ( x.solved [10] == y.solved [10] && x.penalty [10] == y.penalty [10] && x.teamNumber < y.teamNumber ) return true;
    return false;
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);

    int testCase;
    scanf ("%d", &testCase);
    getchar ();

    bool blank = false;
    char input [1000];

    gets (input);

    while ( testCase-- )
    {
        reset ();

        while ( gets (input) && strlen (input) )
        {
            int c, p, t;
            char l;

            sscanf (input, "%d %d %d %c", &c, &p, &t, &l );

            a [c].submit = true;

            if ( l == 'R' || l == 'U' || l == 'E' ) continue;

            if ( l == 'C' )
            {
                if ( !a [c].solved [p] )
                {
                    a [c].solved [p] = 1;
                    a [c].penalty [p] += t;
                }
            }
            else
            {
                if ( !a [c].solved [p] )
                    a [c].penalty [p] += 20;
            }
        }

        calculateAll ();

        sort (a, a + 105, cmp);

        if ( blank )
            printf ("\n");
        blank = true;

        for ( int i = 0; i <= 105; i++ )
        {
            if ( a [i].submit )
                printf ("%d %d %d\n", a [i].teamNumber, a [i].solved [10], a [i].penalty [10]);
        }
    }

    return 0;
}