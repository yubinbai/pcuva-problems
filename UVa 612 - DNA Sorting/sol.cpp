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
struct sequence
{
    string ch;
    int measure;
} a [100 + 3];
int countMeasure (string p)
{
    int cnt = 0;
    for ( int i = 0; p [i]; i++ )
    {
        for ( int j = i + 1; p [j]; j++ )
            if ( p [i] > p [j] ) cnt++;
    }
    return cnt;
}
bool cmp (sequence x, sequence y)
{
    if ( x.measure < y.measure ) return true;
    return false;
}
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    bool blank = false;
    while ( testCase-- )
    {
        int n, m;
        scanf ("%d %d", &n, &m);
        for ( int i = 0; i < m; i++ )
        {
            cin >> a [i].ch;
            a [i].measure = countMeasure (a [i].ch);
        }
        stable_sort (a, a + m, cmp);
        if ( blank ) printf ("\n");
        blank = true;
        for ( int i = 0; i < m; i++ )
            cout << a [i].ch << endl;
    }
    return 0;
}