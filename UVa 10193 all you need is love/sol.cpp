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
int binToDec(string str)
{
    int LEN = str.length() - 1, i, mul = 1;
    int val = 0;
    FOD(i, LEN, 0)
    {
        val += (str[i] - '0') * mul;
        mul *= 2;
    }
    return val;
}
int gcd(int A, int B)
{
    if (A < B)
        return gcd(B, A);
    if (B == 0)
        return A;
    return gcd(B, A % B);
}
int main()
{
    int test, t;
    cin >> test;
    FOI(t, 1, test)
    {
        string S1, S2;
        cin >> S1 >> S2;
        int V1 = binToDec(S1);
        int V2 = binToDec(S2);
        int V = gcd(V1, V2);
        if (V > 1)
            cout << "Pair #" << t << ": All you need is love!\n";
        else
            cout << "Pair #" << t << ": Love is not all you need!\n";
    }
    return 0;
}