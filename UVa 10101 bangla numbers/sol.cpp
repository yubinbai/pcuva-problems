#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long val, test = 1;
    while (scanf("%ld", &val) != EOF)
    {
        string master[] = {" kuti", " lakh", " hajar", " shata", " kuti", " lakh", " hajar", " shata", ""};
        long long n = val;
        long long num[9] = {0};
        num[8] = n % 100; n /= 100;
        num[7] = n % 10;  n /= 10;
        num[6] = n % 100; n /= 100;
        num[5] = n % 100; n /= 100;
        num[4] = n % 100; n /= 100;
        num[3] = n % 10;  n /= 10;
        num[2] = n % 100; n /= 100;
        num[1] = n % 100; n /= 100;
        num[0] = n % 100; n /= 100;
        int i = 0;
        while (num[i] == 0) i++;
        printf("%4d.", test++);
        for (i = 0; i < 9; i++)
        {
            if (num[i] != 0)
                cout << " " << num[i] << master[i];
        }
        printf("\n");
    }
    return 0;
}