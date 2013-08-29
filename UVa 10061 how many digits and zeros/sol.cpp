#include <stdio.h>
#include <string.h>
#include <math.h>
int nN, nB;
int nDivisor[1000];
int GetDigit(int nN, int nB)
{
    double fSum = 0.0;
    for (int i = 2; i <= nN; ++i)
    {
        fSum += log10(i);
    }
    fSum /= log10(nB);
    return floor(fSum + 1e-9) + 1;
}
int GetZero(int nN, int nB)
{
    memset(nDivisor, 0, sizeof(nDivisor));
    for (int i = 2; i <= nN; ++i)
    {
        int nTemp = i;
        for (int j = 2; j <= nTemp && j <= nB; ++j)//这样循环就可以进行素数因子分解了
        {
            while (nTemp % j == 0)
            {
                nDivisor[j]++;
                nTemp /= j;
            }
        }
    }
    int nAns = 0;
    while (1)
    {
        int nTemp = nB;
        for (int j = 2; j <= nTemp; ++j)//分解nB
        {
            while (nTemp % j == 0)
            {
                if (nDivisor[j] > 0)//如果还可以继续分解
                {
                    --nDivisor[j];
                }
                else //直接可以goto跳出多重循环了
                {
                    goto out;
                }
                nTemp /= j;
            }
        }
        ++nAns;
    }
out:
    return nAns;
}
int main()
{
    while (scanf("%d%d", &nN, &nB) == 2)
    {
        int nDigit = GetDigit(nN, nB);
        int nZero = GetZero(nN, nB);
        printf("%d %d\n", nZero, nDigit);
    }
    return 0;
}