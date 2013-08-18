#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;


int main ()
{
    int n;

    while ( scanf ("%d", &n) && n )
    {
        char num [20];
        int chainLength = 1;
        sprintf (num, "%d", n);

        printf ("Original number was %d\n", n);

        sort (num, num + strlen (num));

        char num2 [20];
        strcpy (num2, num);

        reverse (num2, num2 + strlen (num2));

        int first = atoi (num2);
        int second = atoi (num);
        int subs = first - second;
        printf ("%d - %d = %d\n", first, second, subs);
        map <int, bool> m;

        while ( m [subs] == false )
        {
            m [subs] = true;

            sprintf (num, "%d", subs);
            sort (num, num + strlen (num));
            strcpy (num2, num);
            reverse (num2, num2 + strlen (num2));

            first = atoi (num2);
            second = atoi (num);
            subs = first - second;

            printf ("%d - %d = %d\n", first, second, subs);
            chainLength++;
        }

        printf ("Chain length %d\n\n", chainLength);
    }

    return 0;
}