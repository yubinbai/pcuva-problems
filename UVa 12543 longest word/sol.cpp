#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<cctype>
#include<map>
#include<stack>
#include<cstdlib>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
#define ll long long
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
int main()
{
    char s[1000005], a[1000005];
    int max = 1;
    while (sc("%s", s))
    {
        if (!strcmp(s, "E-N-D"))
            break;
        int l = strlen(s);
        int c = 0;
        for (int i = 0; i < l; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] == '-')
                continue;
            else
                c++;
        }
        l = l - c;
        if (max < l)
        {
            max = l;
            strcpy(a, s);
        }
    }
    int l = strlen(a);
    for (int i = 0; i < l; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            pf("%c", a[i] + 32);
        else if (a[i] >= 'a' && a[i] <= 'z' || a[i] == '-')
            pf("%c", a[i]);
    }
    pf("\n");
    return 0;
}