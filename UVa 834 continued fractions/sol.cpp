#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<int, int> mii;
int main()
{
    int a, b, r;
    while (cin >> a >> b)
    {
        printf("[%d", a / b);
        r = a % b; a = b; b = r;
        if (b == 0 || a == 0)
        {
            putchar(']');
            continue;
        }
        putchar(';');
        bool first = true;
        while (b > 0)
        {
            if (first) first = false;
            else putchar(',');
            printf("%d", a / b);
            r = a % b; a = b; b = r;
        }
        printf("]\n");
    }
    return 0;
}
