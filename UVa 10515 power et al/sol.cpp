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
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define REP(i, N) for(i=1; i<=N; i++)
int main()
{
    int vec[10][4];
    vec[0][0] = 0; vec[0][1] = 0; vec[0][2] = 0; vec[0][3] = 0;
    vec[1][0] = 1; vec[1][1] = 1; vec[1][2] = 1; vec[1][3] = 1;
    vec[2][0] = 6; vec[2][1] = 2; vec[2][2] = 4; vec[2][3] = 8;
    vec[3][0] = 1; vec[3][1] = 3; vec[3][2] = 9; vec[3][3] = 7;
    vec[4][0] = 6; vec[4][1] = 4; vec[4][2] = 6; vec[4][3] = 4;
    vec[5][0] = 5; vec[5][1] = 5; vec[5][2] = 5; vec[5][3] = 5;
    vec[6][0] = 6; vec[6][1] = 6; vec[6][2] = 6; vec[6][3] = 6;
    vec[7][0] = 1; vec[7][1] = 7; vec[7][2] = 9; vec[7][3] = 3;
    vec[8][0] = 6; vec[8][1] = 8; vec[8][2] = 4; vec[8][3] = 2;
    vec[9][0] = 1; vec[9][1] = 9; vec[9][2] = 1; vec[9][3] = 9;
    while (true)
    {
        string bas, exp;
        cin >> bas >> exp;
        if (bas == "0" && exp == "0")
            break;
        int b = (int)bas.length();
        int e = (int)exp.length();
        int base = (int)(bas[b - 1] - '0');
        int expo = (int)(exp[e - 1] - '0');
        if (exp.length() > 1)
            expo += (int)(exp[e - 2] - '0') * 10;
        int val = 0;
        if (base == 0)
        {
            val = 0;
        }
        else if (exp[0] == '0' && expo == 0)
        {
            val = 1;
        }
        else
        {
            int inX = (base % 10);
            int inY = (expo % 4);
            val = vec[inX][inY];
        }
        cout << val << endl;
    }
    return 0;
}