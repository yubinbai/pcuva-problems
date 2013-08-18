#include <stdio.h>
#include <math.h>
#define MAX 19000000

unsigned long long int list1[MAX], list2[MAX];
int prime[MAX];

//Sieve Algorithm
void sieve_prime()
{
    int i, j, k, l, m, count = 0;
    unsigned long long int t = 0;
    unsigned long long int serial;
    for (i = 2; i <= MAX; i++)prime[i] = 1;
    k = 2;
    for (m = 2; m <= sqrt(MAX); m++)
    {
        for (j = k + k; j <= MAX; j = j + k)
        {
            prime[j] = 0;

        }
        k++;
        for (; !prime[k]; k++);
    }
    for (i = 0; i <= MAX; i++)
    {
        if (prime[i])
        {

            if (prime[i + 2])
            {
                list1[t] = i;
                list2[t] = i + 2;
                t++;
            }

        }
    }

}

int main()
{
    sieve_prime();
    unsigned long long int serial, n1, n2, u, flag, count;
    //freopen("in543.txt","r",stdin);
    while (scanf("%llu", &serial) == 1 && serial != 0)
    {
        flag = 0;
        count = 0;
        for (u = 2; u <= serial; u++)
        {
            if (prime[u] == 1 && prime[serial - u] == 1)
            {
                flag = 1;
                n1 = u;
                n2 = serial - u;
                break;
            }

        }
        if (flag == 0)printf("Goldbach's conjecture is wrong.\n");
        else if (flag)printf("%llu = %llu + %llu\n", serial, n1, n2);

    }



    return 0;
}