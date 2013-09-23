#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxp = 100010;
int a[maxp];
int y, p;
bool readfile()
{
    if (cin.eof()) return (false);
    cin >> y;
    cin >> p;
    if (cin.eof()) return (false);
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= p; i++) cin >> a[i];
    return (true);
}
int BSearch(int i, int j, int x)
{
    int l, r, m;
    l = i; r = j;
    do
    {
        m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    while (r - l > 1);
    if (a[r] <= x) return (r);
    else return (l);
}
void solve()
{
    int result = 0, d, c;
    for (int i = 1; i <= p; i++)
    {
        int dd = i;
        int cc = BSearch(i, p, a[i] + y - 1);
        if (cc - dd + 1 > result)
        {
            result = cc - dd + 1;
            d = dd; c = cc;
        }
    }
    cout << result << " " << a[d] << " " << a[c] << endl;
}
int main()
{
    while (readfile()) solve();
    return 0;
}
