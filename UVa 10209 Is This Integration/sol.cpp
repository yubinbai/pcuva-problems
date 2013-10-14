#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const long double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164;

long double z(long double x, long double a)
{
    return (x * sqrt(a * a - x * x) + a * a * atan(x / (sqrt(a * a - x * x)))) / 2.0;
}

int main()
{
    ios::sync_with_stdio(false);
    long double a;
    while (cin >> a)
    {
        if (a > 0.000000000001)
        {
            long double checkered = (a * a / 2 - (z(a / 2, a) - z(0, a))) * 2;
            long double dotted = a * a - PI * a * a / 4 - 2 * checkered;
            long double striped = a * a - 4 * checkered - 4 * dotted;

            cout << fixed << setprecision(3) << striped << " " << 4 * dotted << " " << 4 * checkered << endl;
        }
        else
        {
            cout << "0.000 0.000 0.000" << endl;
        }
    }
    return 0;
}