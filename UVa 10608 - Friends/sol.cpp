#include <stdio.h>
#define max(a,b) (a>b)?a:b
int set[30005];
int count[30005];
int getParent(int i, int *set)
{
    if (i == set[i])
        return i;
    else
        return (set[i] = getParent(set[i], set));
}
int isUnion(int a, int b, int *set)
{
    return getParent(a, set) == getParent(b, set);
}
void makeUnion(int a, int b, int *set)
{
    set[getParent(a, set)] = getParent(b, set);
}
int main()
{
    int c, i, k, n, m;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d %d", &n, &m);
        for (i = 1; i <= n; i++)
            count[set[i] = i] = 0;
        while (m--)
        {
            scanf("%d %d", &i, &k);
            makeUnion(i, k, set);
        }
        for (k = 1; k <= n; k++)
            count[getParent(k, set)]++;
        m = 1;
        for (i = 1; i <= n; i++)m = max(m, count[i]);
        printf("%d\n", m);
    }
    return 0;
}