#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
bool cmp(int xx, int yy)
{
    return xx > yy;
}
int a[11111];
inline void decode(int n, int f)
{
    for (int i = 2; i <= (int)sqrt(n + 0.5); i++)
    {
        while (0 == n % i)
        {
            a[i] += f;
            n /= i;
        }
    }
    a[n] += f;
}
int main()
{
    int p, q, r, s;
    while (cin >> p >> q >> r >> s)
    {
        int i, j;
        double ans = 1.0;
        memset(a, 0, sizeof(a));
        for (i = p, j = r; i > q || j > s; )
        {
            if (i > q)
            {
                decode(i, 1);
                i--;
            }
            if (j > s)
            {
                decode(j, -1);
                j--;
            }
        }
        for (i = p - q; i > r - s; i--) decode(i, -1);
        for (i = r - s; i > p - q; i--) decode(i, 1);
        int sthresh = MAX(p, r);
        for (i = 2; i <= sthresh; i++)
        {
            while (a[i] < 0)
            {
                a[i]++;
                ans /= i;
            }
            while (a[i] > 0)
            {
                a[i]--;
                ans *= i;
            }
        }
        cout << fixed << setprecision(5);
        cout << ans << endl;
    }
    return 0;
}
