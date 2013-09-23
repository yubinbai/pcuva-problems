#include <iostream>
using namespace std;
int main()
{
    int n, k;
    unsigned long long r;
    while (cin >> n >> k && ((n != 0) || (k != 0)))
    {
        r = 1;
        if (k > (n / 2))
        {
            k = n - k;
        }
        for (int i = 0; i < k; i++)
        {
            r = r * (n - i);
            r = r / (1 + i);
        }
        cout << r << endl;
    }
}
