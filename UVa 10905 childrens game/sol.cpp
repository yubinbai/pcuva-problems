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
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;
bool cmp (string x, string y)
{
    string t1 = x + y;
    string t2 = y + x;
    if ( t1 > t2 ) return true;
    return false;
}
int main ()
{
    int n;
    string a [50 + 5];
    while ( scanf ("%d", &n) && n )
    {
        for ( int i = 0; i < n; i++ )
            cin >> a [i];
        sort (a, a + n, cmp);
        for ( int i = 0; i < n; i++ )
            cout << a [i];
        printf ("\n");
    }
    return 0;
}
