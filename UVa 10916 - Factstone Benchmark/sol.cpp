#include<stdio.h>
#include<math.h>

int main()
{
    int year;
    while (scanf("%d", &year), year)
    {
        int n = (year - 1940) / 10;
        double k = pow ( 2, n) * log10(2), sum = 0;
        for (int i = 1; ; i++)
        {
            sum += log10(i);
            if (sum > k)
            {
                printf("%d\n", i - 1);
                break;
            }
        }
    }
    return 0;
}