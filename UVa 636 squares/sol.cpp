#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
long mystrtol(char *str, int b)
{
    long result = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        result = result * b + str[i] - '0';
    }
    return result;
}
int main()
{
    char str[100];
    char *end;
    long a, i, max;
    while ( true )
    {
        scanf("%s", str);
        if ( str[0] == '0' )
            break;
        max = 0;
        for ( i = strlen(str) - 1; i >= 0 ; i--)
            if ( str[i] - '0' > max )
                max = str[i] - '0';
        for (i = max + 1; i < 100; i++)
        {
            a = mystrtol(str, i);
            if ( (long)sqrt( a ) * (long)sqrt( a ) == a)
                break;
        }
        printf("%ld\n", i);
    }
    return 0;
}