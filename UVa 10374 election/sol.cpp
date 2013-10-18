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
    int T;
    cin >> T;
    while (T--)
    {
        map<string, string> Party;
        map<string, string>::iterator itp;
        map<string, int> Vote;
        map<string, int>::iterator itv;
        int N, i, j;
        string str;
        cin >> N;
        getline(cin, str);
        while (N--)
        {
            string A, B;
            getline(cin, A);
            getline(cin, B);
            Party[A] = B;
            Vote[A] = 0;
        }
        cin >> N;
        getline(cin, str);
        int maxm = 0;
        while (N--)
        {
            getline(cin, str);
            Vote[str] += 1;
            maxm = max(maxm, Vote[str]);
        }
        int cnt = 0;
        for (itv = Vote.begin(); itv != Vote.end(); itv++)
        {
            if (maxm == (*itv).second)
            {
                ++cnt;
                str = Party[(*itv).first];
            }
        }
        if (cnt > 1)
            cout << "tie" << endl;
        else
            cout << str << endl;
        if (T)
            cout << endl;
    }
    return 0;
}