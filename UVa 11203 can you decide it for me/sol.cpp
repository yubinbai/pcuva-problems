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
#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int Q = 0, M = 0, E = 0;
        int L = S.length();
        int i, j;
        FOI(i, 0, L - 1)
        {
            if (S[i] == '?') ++Q;
            if (S[i] == 'M') ++M;
            if (S[i] == 'E') ++E;
        }
        if (Q + M + E != L || M != 1 || E != 1 || Q < 4)
        {
            cout << "no-theorem\n";
            continue;
        }
        int q1 = 0, q2 = 0, q3 = 0;
        int iM = (int) S.find("M");
        int iE = (int) S.find("E");
        if (!(iM > 0 && iE > iM + 1 && iE < L - 2))
        {
            cout << "no-theorem\n";
            continue;
        }
        FOI(i, 0, iM - 1)
        if (S[i] == '?') ++q1;
        FOI(i, iM + 1, iE - 1)
        if (S[i] == '?') ++q2;
        FOI(i, iE + 1, L - 1)
        if (S[i] == '?') ++q3;
        if (q1 > 0 && q2 > 0 && q3 > 1 && q2 == q3 - q1)
            cout << "theorem\n";
        else
            cout << "no-theorem\n";
    }
    return 0;
}