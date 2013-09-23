#include <iostream>
#include <limits.h>
using namespace std;

const int N1 = 50001, N2 = 5133;

int totient[N1];

void sieveAndTotient()
{
    int i, j;
    bool isPrime[N1];
    // reset
    for (i = 0; i < N1; ++i)
        totient[i] = i;
    for (i = 3; i < N1; i += 2)
        isPrime[i] = true;
    for (i = 4; i < N1; i += 2)
        isPrime[i] = false;
    isPrime[2] = true;
    // sieve
    int cum = 1;
    for (i = 2; i < N1; i++)
    {
        if (isPrime[i])
        {
            // update for i
            if (i < INT_MAX)
                for (j = i; j < N1; j += i)
                {
                    isPrime[j] = false;
                    // totient for i
                    totient[j] -= totient[j] / i;
                }
            isPrime[i] = true;
        }
        // accumulate (modified)
        totient[i] = (cum += totient[i] * 2);
    }
}

int main()
{
    sieveAndTotient();
    int in;
    while (cin >> in && in != 0)
        cout << totient[in] << endl;
    return 0;
}