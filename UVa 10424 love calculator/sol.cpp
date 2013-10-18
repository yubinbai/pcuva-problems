#include<iostream>
#include<stdio.h>
using namespace std;
long long digSum(long long n)
{
    long long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main()
{
    string strA, strB;
    while (getline(cin, strA) && getline(cin, strB))
    {
        int lenA = strA.length(), lenB = strB.length(), i;
        long long sumA = 0, sumB = 0;
        for (i = 0; i < lenA; i++)
        {
            if (isalpha(strA[i]))
            {
                if (isupper(strA[i]))
                    sumA += (strA[i] - 'A' + 1);
                else
                    sumA += (strA[i] - 'a' + 1);
            }
        }
        while (sumA > 9)
            sumA = digSum(sumA);
        for (i = 0; i < lenB; i++)
        {
            if (isalpha(strB[i]))
            {
                if (isupper(strB[i]))
                    sumB += (strB[i] - 'A' + 1);
                else
                    sumB += (strB[i] - 'a' + 1);
            }
        }
        while (sumB > 9)
            sumB = digSum(sumB);

        double ratio;
        if (sumA <= sumB)
            ratio = (double)sumA / (double)sumB;
        else
            ratio = (double)sumB / (double)sumA;
        ratio *= 100.00;
        printf("%.2lf", ratio);
        cout << " %\n";
    }
    return 0;
}