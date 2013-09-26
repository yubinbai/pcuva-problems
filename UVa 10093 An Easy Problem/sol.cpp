#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;
char input [10000];
int len_input;
int getVal (char v)
{
    if (v >= '0' && v <= '9')
        return v - '0';
    else if (v >= 'A' && v <= 'Z')
        return v - 'A' + 10;
    else return v - 'a' + 36;
}
int findBase ()
{
    char maxi = '1';
    for (int i = 0; i < len_input; i++)
        if (maxi < input [i])
            maxi = input [i];
    return getVal (maxi) + 1;
}
void fix_it ()
{
    len_input = strlen (input);
    if (isalnum(input [0]))
        return;
    int len = strlen (input);
    for (int i = 1; i <= len; i++)
        input [i - 1] = input [i];
    len_input = strlen (input);
}
int main ()
{
    while (scanf ("%s", input) == 1)
    {
        fix_it ();
        bool baseFound = false;
        int sum = 0;
        for (int i = 0; i < len_input; i++)
            sum += getVal (input [i]);
        for (int i = findBase(); i <= 62; i++)
        {
            if (sum % (i - 1) == 0)
            {
                printf ("%d\n", i);
                baseFound = true;
                break;
            }
        }
        if (!baseFound)
            printf ("such number is impossible!\n");
    }
    return 0;
}