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
typedef long long int64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
int main()
{
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);
    map <int64, bool> Map;
    vector< int64 > V;
    V.push_back(1); V.push_back(2); V.push_back(3); V.push_back(5); V.push_back(7);
    Map[1] = true; Map[2] = true; Map[3] = true; Map[5] = true; Map[7] = true;
    int64 i, j;
    for (i = 0; ; i++)
    {
        for (j = 0; j <= i; j++)
        {
            int64 val = V[i] * V[j];
            if (!Map[val])
            {
                V.push_back(val);
                Map[val] = true;
            }
        }
        if (V.size() > 14000)
            break;
    }
    sort(V.begin(), V.end());
    while (true)
    {
        int64 N;
        cin >> N;
        if (N == 0)
            break;
        int64 mod10 = N % 10;
        int64 mod100 = (N % 100) / 10;
        string str;
        if (mod10 == 1 && mod100 != 1)
            str = "st";
        else if (mod10 == 2 && mod100 != 1)
            str = "nd";
        else if (mod10 == 3 && mod100 != 1)
            str = "rd";
        else
            str = "th";
        cout << "The " <<  N << str << " humble number is " << V[N - 1] << ".\n";
    }
    return 0;
}
