#include <stdio.h>
#include <string.h>

int main()
{
    int nCases;
    int nN;
    double a0, an1;
    double a1;
    double ci[3000 + 10];
    double c;
    double sum;

    scanf("%d", &nCases);

    while (nCases--)
    {
        scanf("%d", &nN);
        scanf("%lf%lf", &a0, &an1);

        sum = 0.0;
        memset(ci, 0, sizeof(ci));
        for (int j = 1; j <= nN; ++j)
        {
            scanf("%lf", &c);
            ci[j] = ci[j - 1] + c;//ci[j]代表数列ci中第1-j项的和
            sum += ci[j];
        }

        a1 = (nN * a0 + an1 - 2 * sum) / (nN + 1);
        printf("%.2f", a1);
        putchar('\n');

        if (nCases)
        {
            putchar('\n');
        }
    }

    return 0;
}