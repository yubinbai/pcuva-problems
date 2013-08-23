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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

int variable_length;
bool constraint [26 + 5] [26 + 5];
bool avail [26 + 5];
char output [30];
char variable [30];

void reset ()
{
    for ( int i = 0; i < 26 + 5; i++ )
        memset (constraint [i], false, sizeof (constraint [i]));
    memset (avail, true, sizeof (avail));
}

bool check_constraint (int len, int in)
{
    for ( int i = 0; i < len; i++ )
    {
        if ( constraint [in] [output [i] - 'a'] == true ) return false;
    }

    return true;
}

void backtrack (int len)
{
    if ( len == variable_length )
    {
        for ( int i = 0; i < len; i++ ) printf ("%c", output [i]);
        printf ("\n");
        return;
    }

    for ( int i = 0; i < variable_length; i++ )
    {
        if ( avail [i] && check_constraint (len, variable [i] - 'a') )
        {
            output [len] = variable [i];
            avail [i] = false;
            backtrack (len + 1);
            avail [i] = true;
        }
    }
}

int main ()
{
    char input [500];
    bool blank = false;

    while ( gets (input) )
    {
        variable_length = 0;

        for ( int i = 0; input [i]; i++ )
            if ( isalpha (input [i]) ) variable [variable_length++] = input [i];

        sort (variable, variable + variable_length);

        reset ();

        gets (input);
        char first;
        char second;

        for ( int i = 0; input [i]; i++ )
        {
            if ( isalpha (input [i]) )
            {
                first = input [i];
                i++;
                while ( !isalpha (input [i]) ) i++;
                second = input [i];
                constraint [first - 'a'] [second - 'a'] = true;
            }
        }

        if ( blank ) printf ("\n");
        blank = true;

        backtrack (0);
    }

    return 0;
}
