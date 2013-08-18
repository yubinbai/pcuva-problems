#include <stdio.h>

int coins[5] = {1, 5, 10, 25, 50};
#define MAXcoins 7500
long long int memo[MAXcoins + 1];

void count()
{
    int i, j;
    memo[0] = 1;
    for (i = 0; i < 5; i++)
        for (j = coins[i]; j <= MAXcoins; j++)
            memo[j] += memo[j - coins[i]];
}

int main()
{
    count();
    int input;
    while (scanf("%d", &input) == 1)
        printf("%lld\n", memo[input]);
    return 0;
}