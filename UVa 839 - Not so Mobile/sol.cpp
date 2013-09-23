#include <stdio.h>
int ok;
int dfs()
{
    int w1, d1, w2, d2;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if (w1 && w2 && d1 && d2)
    {
        if ( (w1 * d1) != (w2 * d2) )
        {
            ok = 0;
            return 0;
        }
        else
            return (w1 + w2);
    }
    else
    {
        if (!w1)  w1 = dfs();
        if (!w2)  w2 = dfs();
        if ( (w1 * d1) != (w2 * d2) )
        {
            ok = 0;
            return 0 ;
        }
        else    return (w1 + w2);
    }
}
int main()
{
    int i, N; struct BTree *T;  int sum;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        ok = 1; dfs();
        if ( ok == 1 )
            printf("YES\n");
        else
            printf("NO\n");
        if (i != N)  printf("\n");
    }
    return 0;
}