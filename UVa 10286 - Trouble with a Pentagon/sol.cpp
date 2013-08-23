#include<iostream>
#include<cmath>
#include "stdio.h"
#define PI acos(-1)

using namespace std;
int main()
{
    double penta, square, conv = sin(108 * PI / 180) / sin(63 * PI / 180);
    while (cin >> penta)
    {
        square = conv * penta;
        printf("%.10f\n", square);
    }
}