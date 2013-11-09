#include <stdio.h>
#define N 1000011
unsigned long long int res[N];
int main()
{
    int i, j;
    for (i = 0; i < N; i++)
        res[i] = 0;
    res[6] = 1;
    for (i = 1; i <= 3; i++)
        for (j = 6; j <= N - i; j++)
            res[j + i] += res[j];
    j = 1;
    while (scanf("%d", &i) && i)
        printf("Case %d: %llu\n", j++, res[i]);
    return 0;
}