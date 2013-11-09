#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int cas;
    int Max, Min, len, n, t, L, S;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d%d", &len, &n);
        Min = 0;
        Max = 0;
        while (n--)
        {
            scanf("%d", &t);
            if (t > len / 2) L = t, S = len - t;
            else L = len - t, S = t;
            Min = max(L, Min);
            Max = max(S, Max);
        }
        printf("%d %d\n", Max, Min);
    }
    return 0;
}