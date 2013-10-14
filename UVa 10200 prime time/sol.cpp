#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int LIM = 10001;
int Cal(int N)
{
    return ( N * N + N + 41 );
}
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; i++)
        if ( N % i == 0 )
            return false;
    return true;
}
int main()
{
    int prime[LIM + 1];
    int i;
    memset(prime, 0, sizeof prime);
    prime[0] = 1;
    for (i = 1; i < LIM; i++)
    {
        bool stat = isPrime( Cal(i) );
        prime[i] = prime[i - 1];
        if ( stat )
            prime[i]++;
    }
    int A, B;
    while ( scanf("%d%d", &A, &B) != EOF )
    {
        int val = 0;
        val = prime[B];
        if ( A > 0 )
            val -= prime[A - 1];
        double per = (double)val / (double)(B - A + 1);
        per *= 10000;
        per = floor( per + 0.5 );
        per /= 100;
        printf("%.2lf\n", per);
    }
    return 0;
}