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
struct Rec
{
    bool div;
    int dep;
    Rec(bool di, int de)
    {
        div = di;
        dep = de;
    }
};
Rec rec(false, 1);
void check(int N)
{
    if (N < 10)
    {
        if (N == 0 || N == 9)
            rec.div = true;
        else
            rec.div = false;
        return;
    }
    int s = 0;
    while (N > 0)
    {
        s += N % 10;
        N /= 10;
    }
    rec.dep++;
    check(s);
}
int main()
{
    while (true)
    {
        string str;
        cin >> str;
        if (str == "0")
            break;
        int sum = 0, i, LEN = str.length() - 1;
        FOI(i, 0, LEN)
        sum += (str[i] - '0');
        rec = Rec(false, 1);
        check(sum);
        if (rec.div)
            cout << str << " is a multiple of 9 and has 9-degree " << rec.dep << ".\n";
        else
            cout << str << " is not a multiple of 9.\n";
    }
    return 0;
}