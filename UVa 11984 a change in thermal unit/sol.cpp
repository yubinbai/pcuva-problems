#include "stdio.h"
int main()
{
    int caseN, c, d;
    scanf("%d\n", &caseN);
    for (int i = 1; i < caseN + 1; ++i)
    {
        scanf("%d %d\n", &c, &d);
        printf("Case %d: %.2f\n", i, c + d * 5.0 / 9.0);
    }
}