#include<stdio.h>
#define M 2000000

char year[M];
int mod(char[], int);

int main()
{
    int lp, hf, bf, fst = 1;
    while (gets(year))
    {
        lp = hf = bf = 0;
        if (!mod(year, 4) && (mod(year, 100) || !mod(year, 400)))
        {
            lp = 1;
            if (!mod(year, 55))
                bf = 1;
        }

        if (!mod(year, 15))
            hf = 1;

        if (fst)
            fst = 0;
        else
            printf("\n");

        if (lp && hf && bf)
            printf("This is leap year.\nThis is huluculu festival year.\nThis is bulukulu festival year.\n");
        else if (lp && hf)
            printf("This is leap year.\nThis is huluculu festival year.\n");
        else if (lp && bf)
            printf("This is leap year.\nThis is bulukulu festival year.\n");
        else if (hf && bf)
            printf("This is huluculu festival year.\nThis is bulukulu festival year.\n");
        else if (lp)
            printf("This is leap year.\n");
        else if (hf)
            printf("This is huluculu festival year.\n");
        else if (bf)
            printf("This is bulukulu festival year.\n");
        else
            printf("This is an ordinary year.\n");
    }
    return 0;
}

int mod(char year[], int n)
{
    int m, i, y = 0;
    for (i = 0; year[i]; i++)
        y = (y * 10 + year[i] - 48) % n;
    return y;
}
