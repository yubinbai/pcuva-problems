#include <set>
#include <cstdio>
using namespace std;
int main()
{
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        int N, M;
        scanf("%d", &N);
        M = N;
        set<int> Set;
        while (true)
        {
            Set.insert(M);
            int temp = 0;
            while (M)
            {
                int R = M % 10;
                temp += R * R;
                M = M / 10;
            }
            if (temp == 1)
            {
                printf("Case #%d: %d is a Happy number.\n", t, N);
                break;
            }
            if (Set.find(temp) != Set.end())
            {
                printf("Case #%d: %d is an Unhappy number.\n", t, N);
                break;
            }
            M = temp;
        }
    }
    return 0;
}