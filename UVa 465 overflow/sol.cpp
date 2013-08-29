#include <stdio.h>
const int MINT = 0x7fffffff;
int main()
{
    char str1[1000], str2[1000], ch;
    while (scanf("%s %c %s", str1, &ch, str2) != EOF)
    {
        printf("%s %c %s\n", str1, ch, str2);
        double a, b;
        sscanf(str1, "%lf", &a);
        sscanf(str2, "%lf", &b);
        if (a > MINT)
            printf("first number too big\n");
        if (b > MINT)
            printf("second number too big\n");
        if ('+' == ch && a + b > MINT)
            printf("result too big\n");
        if ('*' == ch && a * b > MINT)
            printf("result too big\n");
    }
    return 0;
}
