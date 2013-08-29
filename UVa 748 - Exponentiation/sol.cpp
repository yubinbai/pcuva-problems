#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
char a[256];
int len;
char t[6];
int exp;
int m;
void clear()
{
    int i;
    for (i = 0; i < 256; i++)
        a[i] = 0;
    a[0] = 1;
    len = 1;
}
void multiply()
{
    int carry = 0;
    for (int i = 0; i < len; i++)
    {
        carry += a[i] * m;
        a[i] = carry % 10;
        carry /= 10;
    }
    while (carry)
    {
        a[len++] = carry % 10;
        carry /= 10;
    }
}
void print()
{
    int i;
    for (i = 255; a[i] == 0; i--);
    int l = i;
    for (i = 0; a[i] == 0; i++);
    int r = i;
    if (l >= r && r >= exp)
    {
        for (i = l; i >= r; i--)
            printf("%d", a[i]);
        for (i = r - 1; i >= exp; i--)
            printf("0");
        printf(".");
        printf("\n");
    }
    else if (l >= exp && exp > r)
    {
        for (i = l; i >= exp; i--)
            printf("%d", a[i]);
        printf(".");
        for (i = exp - 1; i >= r; i--)
            printf("%d", a[i]);
        printf("\n");
    }
    else if (exp > l && l >= r)
    {
        printf(".");
        for (i = exp - 1; i > l; i--)
            printf("0");
        for (i = l; i >= r; i--)
            printf("%d", a[i]);
        printf("\n");
    }
    else
        printf("error\n");
}
int main()
{
    char r[10];
    int n;
    while (scanf("%s %d", r, &n) != EOF)
    {
        m = 0;
        exp = 0;
        int flag = 0;
        for (int i = 0; i < strlen(r); i++)
        {
            if (isdigit(r[i]))
            {
                m *= 10;
                m += r[i] - '0';
                if (flag)exp++;
            }
            if (r[i] == '.')flag = 1;
        }
        exp *= n;
        clear();
        for (int i = 0; i < n; i++)
        {
            multiply();
        }
        print();
    }
    return 0;
}
