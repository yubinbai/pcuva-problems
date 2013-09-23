#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<size_t> vector_t;
template<typename T> void sieve_of_eratosthenes(size_t upper_limit, T &container, bool include_one = false)
{
    bool sieve[upper_limit + 1]; // input is inclusive range
    for (size_t i(0); i < upper_limit; ++i)
        sieve[i] = true;
    for (size_t i(2); i < sqrt(upper_limit); ++i)
    {
        if (!sieve[i]) continue;
        for (size_t n(i * i); n < upper_limit; n += i)
        {
            sieve[n] = false;
        }
    }
    if (include_one) container.push_back(1);
    for (size_t i(2); i < upper_limit; ++i)
    {
        if (sieve[i]) container.push_back(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    vector_t primes;
    sieve_of_eratosthenes(1000, primes, true);
    int n, c;
    while (cin >> n >> c)
    {
        cout << n << " " << c << ":";
        n = distance(primes.begin(), lower_bound(primes.begin(), primes.end(), n, less_equal<size_t>()));
        for (int i(max(n % 2 ? n / 2 - c + 1 : n / 2 - c, 0)), end(min(n / 2 + c, n)); i < end; ++i)
            cout << " " << primes[i];
        cout << endl << endl;
    }
    return 0;
}