#include <iostream>
using namespace std;
long long count(long long n)
{
    long long result = 0;
    do
    {
        n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
        result++;
    }
    while (n != 1);
    return result;
}
int main(void)
{
    long long i, j;
    while (cin >> i >> j)
    {
        if (i == 0 && j == 0)break;
        if (i > j)
        {
            i ^= j;
            j ^= i;
            i ^= j;
        }
        int c, index = 0;
        long long max = -1;
        for (c = i; c <= j; c++)
        {
            long long a = count(c);
            if (max < a)
            {
                index = c;
                max = a;
            }
        }
        cout << "Between " << i << " and " << j << ", ";
        cout << index << " generates the longest sequence of " << max << " values." << endl;
    }
    return 0;
}