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
#define MAX 1000000
bool self[MAX + 1];
int digSum(int N)
{
    int S = 0;
    while (N > 0)
    {
        S += N % 10;
        N /= 10;
    }
    return S;
}
int main()
{
    memset(self, true, sizeof self);
    int i;
    FOI(i, 1, MAX)
    {
        if (self[i])
        {
            cout << i << endl;
            int j = i + digSum(i);
            while (j <= MAX && self[j])
            {
                self[j] = false;
                j += digSum(j);
            }
        }
    }
    return 0;
}