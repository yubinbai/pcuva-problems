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
#define LIM 1000000
int main()
{
    int i, j;
    vector <int> pri;
    bool vec[LIM];
    memset(vec, true, sizeof(vec));
    vec[0] = false; vec[1] = false;
    for (i = 0; i < LIM; i++)
    {
        if (vec[i] == true)
        {
            for (j = 2 * i; j < LIM; j += i)
            {
                vec[j] = false;
            }
        }
    }
    FOI(i, 0, LIM)
    {
        if (vec[i])
            pri.push_back(i);
    }
    int SZ = pri.size();
    while (true)
    {
        int N, fac = 0;
        cin >> N;
        if (N == 0)
            break;
        FOI(i, 0, SZ - 1)
        {
            if (N % pri[i] == 0)
            {
                fac++;
            }
        }
        cout << N << " : " << fac << endl;
    }
    return 0;
}