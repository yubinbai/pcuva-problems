#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int N, T, INF = 1 << 29, q;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        vector<int> a;
        while (--N && cin >> q) a.push_back(q);
        int curMax = 0, max = -INF, a0 = 1, maxa0 = 1, maxan = 1;
        for (int i = 0; i < a.size(); ++i)
        {
            curMax += a[i];
            if (curMax > max || (curMax == max && (i + 2 - a0 > maxan - maxa0)))
                max = curMax, maxa0 = a0, maxan = i + 2;
            if (curMax < 0)
                curMax = 0, a0 = i + 2, maxa0 = max <= 0 ? a0 : maxa0;
        }
        if (max <= 0)
            printf("Route %d has no nice parts\n", t);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", t, maxa0, maxan);
    }
    return 0;
}