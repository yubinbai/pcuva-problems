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
using namespace std;

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

int main()
{
    int N, t = 1;
    while ( cin >> N )
    {
        int vec[N];
        int i, j;
        bool isB2 = true;
        FOI(i, 0, N - 1)
        {
            cin >> vec[i];
            if ( vec[i] < 1 )
                isB2 = false;
        }
        map<int, int> Map;
        map<int, int>::iterator it;
        FOI(i, 1, N - 1)
        {
            FOI(j, 0, i)
            {
                ++Map[vec[i] + vec[j]];
                if ( i != j && vec[j] >= vec[i] )
                    isB2 = false;
            }
        }
        for (it = Map.begin(); it != Map.end(); it++)
        {
            if ( (*it).second > 1 )
            {
                isB2 = false;
                break;
            }
        }
        cout << "Case #" << t++ << ":";
        if ( isB2 )
            cout << " It is a B2-Sequence.\n\n";
        else
            cout << " It is not a B2-Sequence.\n\n";
    }
    return 0;
}