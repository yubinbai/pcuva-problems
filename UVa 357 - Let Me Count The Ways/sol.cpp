#include <stdio.h>
unsigned long long int ways[30005];
int coins[] = {1, 5, 10, 25, 50};
int main()
{
    int i, coin, j;
    ways[0] = 1;
    for (i = 0; i < 5; i++)
    {
        coin = coins[i];
        for (j = coin; j < 30005; j++)
            ways[j] += ways[j - coin];

    }
    while (scanf("%d", &i) == 1)
    {
        if (ways[i] != 1)
            printf("There are %llu ways to produce %d cents change.\n", ways[i], i);
        else
            printf("There is only 1 way to produce %d cents change.\n", i);
    }
    return 0;
}