#include <iostream>

#define NDIGITS 100

using namespace std;

/* returns the reversed number */
unsigned long long reverse(unsigned long long number)
{
    unsigned long long m = 0; /* reversed number */
    int digits[NDIGITS]; /* digits array */
    int pos = 0, power = 1;

    /* init */
    for (int i = 0; i < NDIGITS; i++)
    {
        digits[i] = 0;
    }

    /* retrieve all digits */
    while (number > 0)
    {
        digits[pos++] = number % 10;
        number = number / 10;
    }

    /* multiply the reversed digits by the powers of ten */
    for (int i = pos - 1; i >= 0; i--)
    {
        m += power * digits[i];
        power *= 10;
    }

    return m;
}

/* main */
int main()
{
    int nc; /* number of cases */
    int m; /* minimum number of iterations */
    unsigned long long n; /* number */

    cin >> nc;

    /* reverse and add.. */
    for (int i = 0; i < nc; i++)
    {
        cin >> n;
        m = 0;
        while (true)
        {
            if (reverse(n) == n)
            {
                break;
            }
            else
            {
                n += reverse(n);
                m++;
            }
        }
        cout << m << " " << n << endl;
    }

    return 0;
}