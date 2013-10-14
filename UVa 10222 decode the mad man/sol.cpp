#include<iostream>
#include<cstdio>
using namespace std;

string s = "234567890-=@#$%^&*()_+ertyuiop[]ERTYUIOP{}dfghjkl;'DFGHJKL:cvbnm,./CVBNM<>?|\\\"";
string d = "`1234567890~!@#$%^&*()qwertyuiopqwertyuiopasdfghjklasdfghjkzxcvbnm,zxcvbnm,[[l";

int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        int pos = s.find_first_of(c, 0);
        if (pos == -1)putchar(c);
        else putchar(d[pos]);
    }
    return 0;
}