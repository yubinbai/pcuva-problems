#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    while (!(a == 0 && b == 0 && c == 0 && d == 0 && e == 0))
    {
        cout << a *b *c *d *d *e *e << endl;
        cin >> a >> b >> c >> d >> e;
    }
}