#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    while (true)
    {
        int N, i;
        scanf("%d", &N);
        if (!N)
            break;
        int road[N + 2];
        road[0] = 0;
        road[N + 1] = 1422;
        for (i = 1; i <= N; i++)
            scanf("%d", &road[i]);
        N += 2;
        sort(road, road + N);
        bool stat = true;
        for (i = 1; i < N; i++)
        {
            if (road[i] - road[i - 1] > 200)
            {
                stat = false;
                break;
            }
        }
        if (road[N - 1] - road[N - 2] > 100)
            stat = false;
        if (stat)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}