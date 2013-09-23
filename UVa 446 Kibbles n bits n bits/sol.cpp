#include <iostream>

using namespace std;


int main(void)
{
    register int a, b, n, mask;
    register char sign;

    cin >> n;
    while (n--)
    {
        cin >> hex >> a >> sign >> hex >> b;
        mask = 0x2000;
        while (mask > 1) cout << ((a & (mask >>= 1)) > 0);
        cout << " " << sign << " ";
        mask = 0x2000;
        while (mask > 1) cout << ((b & (mask >>= 1)) > 0);
        sign == '+' ? a += b : a -= b;
        cout << " = " << a << endl;
    }
    return 0;
}