#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#define For(a) for ( i = 0; i < a; i++ )
#define Rep(a, b) for ( i = a; i <= b; i++ )
#define N 1000000
using namespace std;
int main ()
{
    int guess;
    char ans1 [10];
    char ans2 [10];
    while ( scanf ("%d", &guess) && guess )
    {
        int high = 11;
        int low = 0;
        while ( scanf ("%s %s", ans1, ans2) && strcmp (ans1, "right") != 0 )
        {
            if ( strcmp (ans2, "high") == 0 )
            {
                if ( guess <= high )
                    high = guess - 1;
            }
            else if ( strcmp (ans2, "low") == 0 )
            {
                if ( guess >= low )
                    low = guess + 1;
            }
            scanf ("%d", &guess);
        }
        if ( guess < low || guess > high || low > high )
            printf ("Stan is dishonest\n");
        else
            printf ("Stan may be honest\n");
    }
    return 0;
}