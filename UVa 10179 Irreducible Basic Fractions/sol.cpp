#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<stdlib.h>
#include<map>
#include<algorithm>
#include<list>
#include<vector>
#include<iostream>
#define pi acos(-1.0)
#define MAX 10000000
#define MIN -2147483647
using namespace std;
typedef long long int ll;
ll totient(ll n)
{
    ll res = 0;
    ll j;
    if (n == 1) return 1;
    res = n;
    if (n % 2 == 0)
    {
        res -= res / 2;
        while (n % 2 == 0) n /= 2;
    }
    for (j = 3; j * j <= n; j += 2)
    {
        if (n % j == 0)
        {
            res -= res / j;
            while (n % j == 0) n /= j;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        cout << totient(n) << endl;
    }
}