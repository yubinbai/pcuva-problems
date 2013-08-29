#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAXN 25
#define INF 1000000
#define exp 0.01
double Profit[MAXN][MAXN][MAXN];
int Trace[MAXN][MAXN][MAXN], oTrace[MAXN];
int nCase;
int floyd()
{
    for (int step = 2; step <= nCase; step++)
        for (int k = 1; k <= nCase; k++)
            for (int i = 1; i <= nCase; i++)
                for (int j = 1; j <= nCase; j++)
                {
                    if (Profit[i][j][step] < Profit[i][k][step - 1] * Profit[k][j][1])
                    {
                        Profit[i][j][step] = Profit[i][k][step - 1] * Profit[k][j][1];
                        Trace[i][j][step] = k;
                        if (Profit[i][j][step] > 1.01 && i == j)
                        {
                            oTrace[0] = step;
                            oTrace[step + 1] = i;
                            while (step > 0)
                            {
                                oTrace[step] = Trace[i][j][step];
                                j = Trace[i][j][step];
                                step--;
                            }
                            return 1;
                        }
                    }
                }
    return 0;
}
int main()
{
    while (scanf("%d", &nCase) == 1)
    {
        memset(Profit, 0, sizeof(Profit));
        memset(Trace, 0, sizeof(Trace));
        for (int i = 1; i <= nCase; i++)
            for (int j = 1; j <= nCase; j++)
            {
                if (i != j)
                {
                    scanf("%lf", &Profit[i][j][1]);
                }
                else Profit[i][j][1] = 1.0;
                Trace[i][j][1] = i;
            }
        if (floyd())
        {
            for (int i = 1; i <= oTrace[0] + 1; i++)
            {
                printf("%d", oTrace[i]);
                if (i != oTrace[0] + 1)
                    printf(" ");
                else printf("\n");
            }
        }
        else printf("no arbitrage sequence exists\n");
    }
    return 0;
}
