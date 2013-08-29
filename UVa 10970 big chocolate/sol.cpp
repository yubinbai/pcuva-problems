#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        printf("%d\n", (a * b) - 1);
    }
    return 0;
}