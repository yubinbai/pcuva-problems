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
typedef pair<int, int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
int main()
{
    string buf;
    int t;
    while (getline(cin, buf))
    {
        istringstream in(buf);
        vi c;
        while (in >> t) c.push_back(t);
        getline(cin, buf);
        istringstream in2(buf);
        bool first = true;
        while (in2 >> t)
        {
            long long res = c[0];
            for (int i = 1; i < c.size(); i++)
            {
                res *= t;
                res += c[i];
            }
            if (first) first = false;
            else putchar(' ');
            printf("%lld", res);
        }
        putchar('\n');
    }
    return 0;
}