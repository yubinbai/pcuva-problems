#include <cstring>
#include <cstdio>
int main()
{
    int T, N;
    char crop[105];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &N);
        scanf("%s", crop);
        bool seen = false;
        int previous, scareCrow = 0;
        for (int i = 0; i < N; i++)
        {
            if (seen)
            {
                if (i - previous == 2)
                {
                    ++scareCrow;
                    seen = false;
                }
                continue;
            }
            if (crop[i] == '.')
            {
                seen = true;
                previous = i;
            }
        }
        if (seen) ++scareCrow;
        printf("Case %d: %d\n", t, scareCrow);
    }
    return 0;
}