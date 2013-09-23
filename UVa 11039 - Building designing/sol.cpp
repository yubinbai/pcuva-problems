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
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    while ( testCase-- )
    {
        int n;
        scanf ("%d", &n);
        int input;
        vector <int> pos;
        vector <int> neg;
        for ( int i = 0; i < n; i++ )
        {
            scanf ("%d", &input);
            if ( input > 0 ) pos.push_back (input);
            else neg.push_back (input * -1);
        }
        sort (pos.begin (), pos.end ());
        sort (neg.begin (), neg.end ());
        int curr = N;
        int cnt = 0;
        if ( pos.back () > neg.back () )
        {
            curr = pos.back ();
            pos.pop_back ();
        }
        else
        {
            curr = neg.back () * -1;
            neg.pop_back();
        }
        cnt++;
        while ( pos.size () && neg.size () )
        {
            if ( curr < 0 )
            {
                while ( pos.size () )
                {
                    if ( pos.back () < curr * -1 )
                    {
                        curr = pos.back ();
                        cnt++;
                        break;
                    }
                    pos.pop_back();
                }
            }
            else
            {
                while ( neg.size () )
                {
                    if ( neg.back () < curr )
                    {
                        curr = neg.back () * -1;
                        cnt++;
                        break;
                    }
                    neg.pop_back ();
                }
            }
        }
        if ( curr < 0 )
        {
            while ( pos.size () )
            {
                if ( pos.back () < curr * -1 )
                {
                    curr = pos.back ();
                    cnt++;
                    break;
                }
                pos.pop_back();
            }
        }
        else
        {
            while ( neg.size () )
            {
                if ( neg.back () < curr )
                {
                    curr = neg.back () * -1;
                    cnt++;
                    break;
                }
                neg.pop_back ();
            }
        }
        printf ("%d\n", cnt);
    }
    return 0;
}
