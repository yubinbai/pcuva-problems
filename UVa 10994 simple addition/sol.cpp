#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>
using namespace std;
typedef pair<int, int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int, int>    mii;
int s[10];
long long v[12];
long long getSum(int n)
{
    if (n <= 0) return 0;
    long long sum = 0;
    int cnt = 0;
    while (n > 0)
    {
        int r = n % 10; n /= 10;
        sum += s[r] + r * v[cnt];
        cnt++;
    }
    return sum;
}
int main()
{
    int p, q;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += i;
        s[i] = sum;
    }
    v[0] = 0; v[1] = 45;
    for (int i = 2; i < 12; i++)
    {
        v[i] = v[i - 1] * 10 + 45;
    }
    while (cin >> p >> q, p >= 0 && q >= 0)
    {
        printf("%lld\n", getSum(q) - getSum(p - 1));
    }
    return 0;
}
