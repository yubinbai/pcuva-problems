#include <stdio.h>
#include <math.h>
unsigned long long s2[101];
unsigned long long r2[101];
unsigned long long s3[101];
unsigned long long r3[101];
unsigned long long s4[101];
unsigned long long r4[101];

int main()
{
    unsigned long long i = 0;
    while (i <= 100)
    {
        s2[i] = i * (i + 1) * (2 * i + 1) / 6;//平方和
        s3[i] = i * i * (i + 1) * (i + 1) / 4;//立方和
        s4[i] = i * (i + 1) * (6 * i * i * i + 9 * i * i + i - 1) / 30;//四次方和
        r2[i] = pow(i * (i + 1) / 2, 2) - s2[i];
        r3[i] = pow(i * (i + 1) / 2, 3) - s3[i];
        r4[i] = pow(i * (i + 1) / 2, 4) - s4[i];
        ++i;
    }

    int nN;
    while (scanf("%d", &nN) != EOF)
    {
        //printf("%I64u %I64u %I64u %I64u %I64u %I64u\n", s2[nN], r2[nN], s3[nN], r3[nN], s4[nN], r4[nN]);
        printf("%llu %llu %llu %llu %llu %llu\n", s2[nN], r2[nN], s3[nN], r3[nN], s4[nN], r4[nN]);
    }

    return 0;
}