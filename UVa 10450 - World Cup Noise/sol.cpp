/*
Shiakh Shiam Rahman
UVa : 10450 - World Cup noise
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>

using namespace std;

int main()
{
    double a[100];
    int c, d = 1, i, b, x = 1;
    a[0] = 1;
    a[1] = 1;
    for (i = 2; i <= 55; i++)
        a[i] = a[i - 1] + a[i - 2];
    scanf("%d", &c);
    while (c >= d)
    {
        scanf("%d", &b);
        if (b < 51)
        {
            if (b == 0)a[b + 1] = 0;
            printf("Scenario #%d:\n%.lf\n\n", d, a[b + 1]);
            x++;
        }
        d++;
    }

    return 0;
}