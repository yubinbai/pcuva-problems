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


int main ()
{
    string dictionary [100 + 5];
    string scramble;
    string end = "XXXXXX";

    int dic_len = 0;

    while ( cin >> dictionary [dic_len] && dictionary [dic_len] != end ) dic_len++;

    sort (dictionary, dictionary + dic_len);

    while ( cin >> scramble && scramble != end )
    {
        sort (scramble.begin (), scramble.end ());
        bool print_one = false;
        for ( int i = 0; i < dic_len; i++ )
        {
            string temp = dictionary [i];
            sort (temp.begin (), temp.end ());
            if ( scramble == temp )
            {
                cout << dictionary [i] << endl;
                print_one = true;
            }
        }

        if ( !print_one ) cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }

    return 0;
}