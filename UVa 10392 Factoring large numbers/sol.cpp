#include <stdio.h>
#include <math.h>
int numbers[1000000];
int primes[78493];
int main()
{

    int i, j, l, counter = 0;
    long long n, pos;
    for (j = 4 ; j < 1000000 ; j += 2)
    {
        numbers[j] = 1;
    }
    primes[counter++] = 2;
    for (i = 3 ; i < 1000000 ; i++)
    {
        if (numbers[i] == 0)
        {
            primes[counter++] = i;
            for (j = i * i ; j < 1000000  && j > 0; j += i * 2)
            {
                numbers[j] = 1;
            }
        }
    }
    while (scanf("%lli", &n) && n > 0)
    {
        pos = sqrt(n);
        for (i = 0 ; i < 78493 && primes[i] <= pos ; i++)
        {
            while (n % primes[i] == 0)
            {
                printf("    %d\n", primes[i]);
                n /= primes[i];
            }
        }

        if (n != 1)
        {
            printf("    %lli\n", n);
        }
        printf("\n");
    }
    return 0;
}