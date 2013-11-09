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
#define pi acos(-1.0)
#define N 1000000
using namespace std;
char input [1000000 + 10];
int cnt;
int recursive (int x0)
{
    sprintf (input, "%d", x0);
    int x1 = strlen (input);
    cnt++;
    if ( x1 == x0 ) return cnt;
    recursive( x1 );
}
int main ()
{
    while ( gets (input) && strcmp (input, "END") )
    {
        if ( strcmp (input, "1") == 0 )
        {
            printf ("1\n");
            continue;
        }
        cnt = 1;
        printf ("%d\n", recursive (strlen (input)));
    }
    return 0;
}