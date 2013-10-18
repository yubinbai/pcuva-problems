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
    int pf;
    int N, X, TC;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> X;
        int tX = X;
        pf = -1;
        while (tX > 0 && !(tX & 1))
        {
            pf++; tX >>= 1;
        }
        if (tX & 1)
        {
            pf++;
        }
        int nOne = 0;
        while (tX > 0)
        {
            nOne++;
            tX &= (tX - 1);
        }
        printf("%d ", nOne + 1);
        if (pf >= 0)
        {
            printf("%d\n", (1 << N) + 1 - (1 << pf));
        }
        else
        {
            printf("1\n");
        }
    }
    return 0;
}