#include <iostream>
using namespace std;

int main()
{
    const int i_max = 10;
    int power_of_10[i_max + 1];
    long long nr_digits[i_max + 1];
    nr_digits[0] = 0;
    for (int i = 1, p = 1; i <= i_max; i++, p *= 10)
    {
        power_of_10[i] = p;
        nr_digits[i] = nr_digits[i - 1] + static_cast<long long>(i) * 9 * p;
    }
    long long n;
    while (cin >> n)
    {
        int i = 1;
        while (i <= i_max && n > nr_digits[i])
            i++;
        long long j = n - nr_digits[i - 1];
        long long m = static_cast<long long>(power_of_10[i] - 1) + (j + i - 1) / i;
        if (j % i)
        {
            for (int k = i - static_cast<int>(j % i); k; k--)
                m /= 10;
        }
        cout << m % 10 << endl;
    }
    return 0;
}