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
#define LL long long
using namespace std;
char input [100];
map <string, bool> visited;
bool is_unique_palindrome (int x, int l)
{
    if ( x >= l ) return false;
    char tmp [100];
    int tmp_len = 0;
    while ( x < l ) tmp [tmp_len++] = input [x++];
    tmp [tmp_len] = 0;
    char rev [100];
    strcpy (rev, tmp);
    reverse (rev, rev + tmp_len);
    if ( strcmp (rev, tmp) == 0 )
    {
        if ( visited [tmp] == true ) return false;
        visited [tmp] = true;
        return true;
    }
    return false;
}
int main ()
{
    while ( cin >> input )
    {
        visited.clear ();
        int len = strlen (input);
        int cnt = 0;
        for ( int i = 0; i < len; i++ )
        {
            for ( int j = 0; j < len; j++ )
            {
                if ( is_unique_palindrome (i, len - j))
                    cnt++;
            }
        }
        printf ("The string '%s' contains %d palindromes.\n", input, cnt);
    }
    return 0;
}