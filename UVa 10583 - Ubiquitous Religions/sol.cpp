#include <stdio.h>
#define max(a,b) (a>b)?a:b
int set[50005];
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
    scanf("%d %d", &n, &m);
    c = 1;
    while (n || m)
    {
        for (i = 1; i <= n; i++)
            set[i] = i;
        while (m--)
        {
            scanf("%d %d", &i, &k);
            makeUnion(i, k, set);
        }
        m = 0;
        for (k = 1; k <= n; k++)
            m += (getParent(k, set) == k);
        printf("Case %d: %d\n", c++, m);
        scanf("%d %d", &n, &m);
    }
    return 0;
}