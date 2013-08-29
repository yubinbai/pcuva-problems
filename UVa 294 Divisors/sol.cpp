#include <iostream>
using namespace std;
const int PSIZE = 3500; // Number of Primes
//find out primes from 1th to 3500th
void find_prime(long prime[])
{
    long gap = 2;
    bool is_prime;
    long may_be_prime = 5;
    int prime_no;
    int i;
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime_no = 3;
    while (prime_no < PSIZE)
    {
        may_be_prime += gap;
        gap = 6 - gap;
        is_prime = true;
        for (i = 0; ((prime[i] * prime[i] <= may_be_prime) && is_prime); i++)
            if (may_be_prime % prime[i] == 0)
                is_prime = false;
        if (is_prime)
            prime[prime_no++] = may_be_prime;
    }
}
//calculate divisor of p
//p=a^m*b^n*c^o...., then divisor = (m+1)*(n+1)*(o+1)....
int find_divisor(long p, long prime[])
{
    int divisor;
    int k;
    int i;
    divisor = 1;
    for (i = 0; i < PSIZE; i++)
    {
        for (k = 0; (p % prime[i] == 0) && (p > 1); k++)
            p = static_cast<long>(static_cast<double>(p) / static_cast<double>(prime[i]));
        if (k > 0)
            divisor = divisor * (k + 1);
        else if (p == 1)
            break;
    }
    if (p > 1)              //p is a big prime and not in prime[PSIZE]
    {
        divisor = divisor * 2;
    }
    return divisor;
}
int main()
{
    int  n;
    long l;
    long u;
    long p;
    int  d;
    long prime[PSIZE];
    int  i;
    long j;
    find_prime(prime);
    //read input
    cin >> n;
    for (i = 0; i < n; i++)
    {
        //read input
        cin >> l >> u;
        //initialize p and d
        p = l;
        d = find_divisor(p, prime);
        //find out the biggest d from l+1 to u
        for (j = l + 1; j <= u; j++)
        {
            int temp = find_divisor(j, prime);
            if (temp > d)
            {
                p = j;
                d = temp;
            }
        }
        //output result
        cout << "Between " << l << " and " << u << ", "
             << p << " has a maximum of " << d << " divisors." << endl;
    }
    return 0;
}