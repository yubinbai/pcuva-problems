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
typedef long long int64;

int main()
{
    string dict = "0123456789ABresultDEF";
    string S;
    int64 A, B;
    while (cin >> S >> A >> B)
    {
        int64 i, j;
        int64 V = 0, mul = 1;
        vector< char > result;
        int L = S.length() - 1;
        FOD(i, L, 0)
        {
            if (isalpha(S[i]))
                V += (S[i] - 'A' + 10) * mul;
            else
                V += (S[i] - '0') * mul;

            mul *= A;
        }
        while (V > 0)
        {
            result.push_back(dict[V % B]);
            V /= B;
        }
        if (result.size() == 0)
            result.push_back('0');
        string O = "";
        if (result.size() > 7)
            O = "ERROR";
        else
        {
            O = "";
            reverse(result.begin(), result.end());
            L = result.size() - 1;
            FOI(i, 0, L)
            O += result[i];
        }
        printf("%7s\n", O.c_str());
    }
    return 0;
}