#include <stdio.h>
#include <string.h>
#include <iostream>
#define Max 1000
using namespace std;
int main ()
{
    char X [Max], Y [Max];
    long Len_X, Len_Y, I, J, K, Temp [Max], Carry;
    while (cin >> X >> Y)
    {
        long Res [Max] = {0};
        Len_X = strlen (X);
        Len_Y = strlen (Y);
        for (J = Len_Y - 1; J >= 0; J--)
        {
            // step by step a X sign appears and increases
            K = 0;
            while (K < ((Len_Y - 1) - J))
                Temp [K++] = 0;
            Carry = 0;
            for (I = Len_X - 1; I >= 0; I--)   // multiplication
            {
                Carry = ((X [I] - '0') * (Y [J] - '0')) + Carry;
                Temp [K++] = Carry % 10;
                Carry /= 10;
            }
            while (Carry)
            {
                Temp [K++] = Carry % 10;
                Carry /= 10;
            }
            for (I = 0; I < K; I++)   // addition with the previous
            {
                Carry = Res [I] + Temp [I] + Carry;
                Res [I] = Carry % 10;
                Carry /= 10;
            }
            while (Carry)
            {
                Res [I++] = Carry % 10;
                Carry /= 10;
            }
        }
        K = I - 1;
        while (Res[K] == 0)
            K--;
        if (K == -1)
            printf("0");
        else
        {
            while (K != -1)
                printf("%ld", Res[K--]);
        }
        printf("\n");
    }
    return 0;
}