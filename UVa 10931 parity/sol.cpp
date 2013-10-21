#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    long long n, p, r;
    int j;
    char bin[100];
    while (cin >> n)
    {
        if (n == 0) break;
        p = 0;
        j = 0;
        while (n != 0)
        {
            r = n % 2;
            n = n / 2;
            p += r;
            bin[j++] = r + 48;
        }
        bin[j] = '\0';
        reverse(bin, bin + j);
        cout << "The parity of " << bin << " is " << p << " (mod 2)." << endl;
    }
    return 0;
}