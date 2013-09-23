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
char a[10 + 3][10 + 3];
int num[10 + 3][10 + 3];
int R, C;
void print_acroos ()
{
    printf ("Across\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (num[i][j])
            {
                printf ("%3d.", num[i][j]);
                while (j != C && a[i][j] != '*') printf ("%c", a[i][j++]);
                printf ("\n");
            }
        }
    }
}
void print_down ()
{
    printf ("Down\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (num[i][j])
            {
                int tmp = i;
                printf ("%3d.", num[i][j]);
                while (tmp != R && a[tmp][j] != '*')
                {
                    printf ("%c", a[tmp][j]);
                    num[tmp++][j] = 0;
                }
                printf ("\n");
            }
        }
    }
}
int main ()
{
    bool blank = false;
    int cases = 0;
    while (scanf ("%d", &R) && R)
    {
        scanf ("%d", &C);
        for (int i = 0; i < R; i++) scanf ("%s", a[i]);
        memset (num, 0, sizeof (num));
        // numbering
        int n = 1;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (a[i][j] != '*')
                {
                    if (i == 0 || j == 0) num[i][j] = n++;
                    else if (a[i][j - 1] == '*' || a[i - 1][j] == '*') num[i][j] = n++;
                }
            }
        }
        if (blank) printf ("\n");
        blank = true;
        printf ("puzzle #%d:\n", ++cases);
        print_acroos ();
        print_down ();
    }
    return 0;
}