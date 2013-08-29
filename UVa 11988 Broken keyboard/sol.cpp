#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int INF = 0x7fffffff;
unsigned long long uINF = ~0LL;
#define MAXN 1007
#define mod 1000000007
typedef long long LL;
char s[100010], ans[100010];
int main()
{
    while (scanf("%s", s) != EOF)
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '[' || s[i] == ']')
                ans[i] = '\0';
            else ans[i] = s[i];
        }
        ans[len] = '\0';
        for (int i = len - 1; i >= 0; i--)
            if (s[i] == '[')
                printf("%s", ans + i + 1);
        if (s[0] != '[' && s[0] != ']')
            printf("%s", ans);
        for (int i = 0; i < len; i++)
            if (s[i] == ']')
                printf("%s", ans + i + 1);
        printf("\n");
    }

    return 0;
}