#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

int main()
{
    int cases, cace = 1;
    scanf("%d", &cases);
    while (cases--)
    {
        int n, temp, result = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &temp);
            result = max(temp, result);
        }
        printf("Case %d: %d\n", cace++, result);
    }
    return 0;
}