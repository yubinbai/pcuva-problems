#include <stdio.h>
#include <string.h>
char s[128] = {'\0'};
int n, b[128] = {0}, lb = 0;
void Transform(int len)
{
    int a[128] = {0}, la = 0; lb = 0;
    for (int i = 0; i < len; i++) a[i] = s[len - 1 - i] - '0';
    while (len)
    {
        int mod = 0, mul;
        for (int i = len - 1; i >= 0; i--)
        {
            mul = mod * 10 + a[i];
            a[i] = mul >> 1;
            mod = mul & 1;
        }
        b[lb++] = mod;
        if (!a[len - 1]) len--;
    }
}
int main()
{
    int tower1 = 0, tower2 = 0, tower3 = 0, tmp;
    while (scanf("%d %s", &n, s) == 2)
    {
        if (!n && s[0] == '0') break;
        Transform(strlen(s));
        tower1 = 0; tower2 = 0; tower3 = 0;
        for (int i = 0; i < lb; i++)
        {
            if (b[i])
            {
                tower3++;
                tmp = tower1; tower1 = tower2; tower2 = tmp;
            }
            else
            {
                tower1++;
                tmp = tower2; tower2 = tower3; tower3 = tmp;
            }
        }
        int left = n - lb;
        if (left & 1)
        {
            tmp = tower2;
            tower2 = tower3;
            tower3 = tmp;
        }
        tower1 += left;
        if (n & 1) printf("%d %d %d\n", tower1, tower3, tower2);
        else printf("%d %d %d\n", tower1, tower2, tower3);
    }
    return 0;
}


