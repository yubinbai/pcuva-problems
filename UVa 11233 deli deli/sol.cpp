#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
using namespace std;
int main()
{
    int L, N, i;
    map <string, string> irr;
    map <string, string>::iterator it;
    cin >> L >> N;
    for (i = 0; i < L; i++)
    {
        string first, second;
        cin >> first >> second;
        irr[first] = second;
    }
    for (i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        it = irr.find(str);
        if (it != irr.end())
        {
            cout << it->second << endl;
            continue;
        }
        int len = str.length();
        if ( str[len - 1] == 'y' && !(str[len - 2] == 'a' || str[len - 2] == 'e' ||
                                      str[len - 2] == 'i' || str[len - 2] == 'o' || str[len - 2] == 'u') )
        {
            str.erase(len - 1);
            str += "ies";
            cout << str << endl;
        }
        else if ( str[len - 1] == 'o' ||  str[len - 1] == 's' ||  str[len - 1] == 'x' ||
                  (str[len - 1] == 'h' && (str[len - 2] == 'c' || str[len - 2] == 's') ) )
        {
            str += "es";
            cout << str << endl;
        }
        else
        {
            str += "s";
            cout << str << endl;
        }
    }
    return 0;
}