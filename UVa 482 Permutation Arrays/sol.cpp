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

struct array
{
    int in;
    string num;
} a [10000];

bool cmp (array x, array y)
{
    if ( x.in < y.in ) return true;
    return false;
}

int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    getchar ();

    bool blank = false;

    while ( testCase-- )
    {
        char input [100000];
        gets (input);
        gets (input);

        char *pch = strtok (input, " ");
        int index = 0;

        while ( pch != NULL )
        {
            a [index].in = atoi (pch);
            pch = strtok (NULL, " ");
            index++;
        }

        gets (input);

        pch = strtok (input, " ");
        index = 0;

        while ( pch != NULL )
        {
            a [index].num = pch;
            pch = strtok (NULL, " ");
            index++;
        }

        sort (a, a + index, cmp);

        if ( blank ) printf ("\n");
        blank = true;

        for ( int i = 0; i < index; i++ )
            cout << a [i].num << endl;
    }

    return 0;
}