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
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;
int mytime;
bool next_time (int t)
{
    if ( t == 2359 )
    {
        mytime = 0;
        return true;
    }
    t++;
    if ( t % 100 == 60 ) mytime = t + 40;
    else mytime = t;
    return true;
}
bool palindrome (int t)
{
    char a [10];
    char rev_a [10];
    sprintf (a, "%d", t);
    strcpy (rev_a, a);
    reverse (rev_a, rev_a + strlen (rev_a));
    if ( strcmp (a, rev_a) == 0 ) return true;
    return false;
}
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    while ( testCase-- )
    {
        int hh, mm;
        scanf ("%d:%d", &hh, &mm);
        mytime = hh * 100 + mm;
        if ( mytime == 2359 )
        {
            printf ("00:00\n");
            continue;
        }
        while ( next_time (mytime) )
        {
            if ( palindrome(mytime) )
            {
                mm = mytime % 100;
                hh = mytime / 100;
                printf("%02d:%02d\n", hh, mm);
                break;
            }
        }
    }
    return 0;
}
