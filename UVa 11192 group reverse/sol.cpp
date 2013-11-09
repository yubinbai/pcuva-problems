#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

int main()
{
    char s[1000];
    int d, len, sublen, n;
    while (scanf("%d\n", &n) == 1)
    {
        if (n == 0) break;
        scanf(" ");
        gets(s);
        len = strlen(s);
        sublen = len / n;
        for (int i = 1; i <= n ; i++)
        {
            d = i * sublen;
            for (int j = d - 1; j >= d - sublen ; j--)
            {
                printf("%c", s[j]);
            }

        }
        printf("\n");
    }
    return 0;
}