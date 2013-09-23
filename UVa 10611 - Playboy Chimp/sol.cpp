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
vector <int> a;
int mid;
void binarySearch (int x, int l, int h)
{
    while ( h - l > 0 )
    {
        int temp = (h + l) / 2;
        if ( temp == mid )
            return;
        mid = temp;
        if ( a [mid] == x )
            return;
        if ( a [mid] < x )
            l = mid;
        else
            h = mid;
        binarySearch (x, l, h);
        return;
    }
}
int main ()
{
    int n;
    scanf ("%d", &n);
    for ( int i = 0; i < n; i++ )
    {
        int input;
        scanf ("%d", &input);
        a.push_back (input);
    }
    unique (a.begin (), a.end ());
    int length = a.size ();
    for ( size_t i = 1; i < a.size (); i++ )
    {
        if ( a [i - 1] >= a [i] )
        {
            length = i;
            break;
        }
    }
    int query;
    scanf ("%d", &query);
    for ( int i = 0; i < query; i++ )
    {
        int q;
        scanf ("%d", &q);
        mid = 0;
        binarySearch (q, 0, length);
        if ( a [mid] == q )
        {
            if ( mid - 1 >= 0 ) printf ("%d", a [mid - 1]);
            else printf ("X");
            if ( mid + 1 < length ) printf (" %d", a [mid + 1]);
            else printf (" X");
            printf ("\n");
        }
        else
        {
            if ( a [mid] < q ) printf ("%d", a [mid]);
            else if ( mid - 1 >= 0 ) printf ("%d", a [mid - 1]);
            else printf ("X");
            if ( a [mid] > q ) printf (" %d", a [mid]);
            else if ( mid + 1 < length ) printf (" %d", a [mid + 1]);
            else printf (" X");
            printf ("\n");
        }
    }
    return 0;
}
