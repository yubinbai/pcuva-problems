#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
    int papeles, cont, res;
    double maximo, a, b, l, s;
    while (scanf("%d", &papeles) != EOF)
    {
        if (papeles == 0)
            break;
        cont = 1, maximo = -1, res = -1;
        while (papeles--)
        {
            scanf("%lf%lf", &a, &b);
            l = max(a, b);
            s = min(a, b);
            if (maximo < max(min(l / 4.0, s), s / 2.0))
            {
                maximo = max(min(l / 4.0, s), s / 2.0);
                res = cont;
            }
            cont++;
        }
        printf("%d\n", res);
    }
    return 0;
}