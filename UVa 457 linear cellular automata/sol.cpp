#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int grow[42], dna[10], res[42];
void init()
{
    for (int i = 0; i < 42; i++)
        grow[i] = 0;
    grow[20] = 1;
}
void oneday()
{
    int temp;
    for (int i = 1; i < 41; i++)
    {
        temp = grow[i] + grow[i - 1] + grow[i + 1];
        res[i] = dna[temp];
    }
}
void print(int grow[])
{
    for (int i = 1; i < 41; i++)
    {
        if (grow[i] == 0) printf(" ");
        else if (grow[i] == 1) printf(".");
        else if (grow[i] == 2) printf("x");
        else if (grow[i] == 3) printf("W");
    }
    printf("\n");
}
int main()
{
    int i, n;
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            for (i = 0; i < 10; i++)
            {
                scanf("%d", &dna[i]);
            }
            init();
            print(grow);
            for (i = 0; i < 49; i++)
            {
                oneday();
                memcpy(grow, res, sizeof(grow));
                print(grow);
            }
            if (n) printf("\n");
        }
    }
    return 0;
}
