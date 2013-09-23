#include <iostream>
#include <map>
using namespace std;
int m[10001]; //Cache
void fact();
int main()
{
    m[0] = 1;
    fact();
    int n;
    while (cin >> n)
    {
        cout.width(5);
        cout.fill(' ');
        cout << n;
        cout << " -> " << m[n] % 10 << endl;
    }
}
void fact()
{
    int f = 1;
    for (int i = 1; i <= 10000; ++i)
    {
        int c = 1;
        while ((i / c) % 10 == 0)
            c *= 10;
        f *= (i / c);
        c = 1;
        while ((f / c) % 10 == 0)
            c *= 10;
        f = (f / c) % 100000;
        m[i] = f;
    }
}
