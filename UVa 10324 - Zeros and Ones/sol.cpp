/////////////////////////////////
// 10324 - Zeros and Ones
/////////////////////////////////
#include<cstdio>
char zerones[1000005];
unsigned int sum[1000005];
unsigned int cnum, diff, i, j, queries;
void check()
{
    while (i < j && zerones[i] == zerones[i + 1]) i++;
}
int main(void)
{
    cnum = 1;
    while (gets(zerones))
    {
        printf("Case %u:\n", cnum++);
        scanf("%u\n", &queries);
        sum[0] = zerones[0] - '0';
        for (i = 1; zerones[i]; i++)
            if (zerones[i] != zerones[i - 1]) sum[i] = sum[i - 1] + 1;
            else sum[i] = sum[i - 1];
        while (queries--)
        {
            scanf("%u %u\n", &i, &j);
            if (i > j) i ^= j ^= i ^= j;
            if (sum[i] == sum[j]) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}