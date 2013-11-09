#include <stdio.h>
#define N 45
unsigned long long int res[45];
int main()
{
    int i, c;
    for (i = 0; i < 43; i++)res[i] = 0;
    res[0] = 1;
    for (i = 0; i < 43; i++)
    {
        res[i + 1] += res[i];
        res[i + 2] += 4 * res[i];
        res[i + 3] += 2 * res[i];
    }
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &i);
        printf("%llu\n", res[i]);
    }
    return 0;
}