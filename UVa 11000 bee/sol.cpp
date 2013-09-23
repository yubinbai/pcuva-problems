#include<stdio.h>
int main()
{
    long int n, i, female, male, total, Male, Female;
    while (1)
    {
        scanf("%ld", &n);
        if (n == -1)
            break;
        female = 1;
        Female = 0;
        total = 1;
        male = 0;
        for (i = 1; i <= n; i++)
        {
            male = total;
            Male = female;
            female = female + Female;
            total = total + female;
            Female = Male;
        }
        printf("%ld %ld\n", male, total);
    }
    return 0;
}
