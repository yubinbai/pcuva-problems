#include <stdio.h>
#define N 30005
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned long long int ways[N];
int main()
{
    int i, j, inp;
    for (i = 0; i < N; i++)
        ways[i] = 0;
    ways[0] = 1;
    for (j = 0; j < 11; j++)
        for (i = 0; i < N; i++)
            if (i >= coins[j])
                ways[i] += ways[i - coins[j]];
    scanf("%d.%d", &i, &j);
    while (i || j)
    {
        inp = i * 100 + j;
        printf("%3d.%.2d%17llu\n", i, j, ways[inp]);
        scanf("%d.%d", &i, &j);
    }
    return 0;
}