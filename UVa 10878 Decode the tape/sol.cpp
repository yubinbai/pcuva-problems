#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define fi "10878.inp"
#define fo "10878.out"
using namespace std;
int main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    char s[20];
    char result;
    gets(s);
    while (gets(s))
    {
        if (strcmp(s, "___________") == 0)
            break;
        result = 0;
        if ( s[9] == 'o' )
            result = result + 1;
        if ( s[8] == 'o' )
            result = result + 2;
        if ( s[7] == 'o' )
            result = result + 4;
        if ( s[5] == 'o' )
            result = result + 8;
        if ( s[4] == 'o' )
            result = result + 16;
        if ( s[3] == 'o' )
            result = result + 32;
        if ( s[2] == 'o' )
            result = result + 64;
        if ( s[1] == 'o' )
            result = result + 128;
        printf("%c", result);
    }
    return 0;
}