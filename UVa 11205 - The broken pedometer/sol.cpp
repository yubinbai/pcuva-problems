#include <cstdio>
#include <cstring>
#include <ctime>
#include <set>

using namespace std;

#define MAXN            100
#define MAXP            16

int P, N;
int maxsp;      // max suppress LED number

bool check(int S[][MAXP], int *mask)
{
    set<int> s;
    for (int i = 0; i < N; i++) // check all numbers
    {
        int t = 0;
        for (int j = 0; j < P; j++) // check all LEDs
            if (!mask[j] && S[i][j]) t += 1 << j;

        if (s.find(t) != s.end()) return false;
        else s.insert(t);
    }
    return true;
}

void solve(int S[][MAXP], int *mask, int cur)
{
    if (cur == P)
    {
        int cnt = 0;
        for (int i = 0; i < P; i++) if (mask[i]) cnt++;
        if (maxsp < cnt) maxsp = cnt;
    }
    else
    {
        mask[cur] = 1;
        if (check(S, mask)) solve(S, mask, cur + 1);
        mask[cur] = 0;
        solve(S, mask, cur + 1); // not change mask
    }
}

int S[MAXN][MAXP], mask[MAXP];

void init()
{
    maxsp = 0;
    memset(mask, 0, sizeof(mask));
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
#endif

    int nr_cases;
    scanf("%d", &nr_cases);
    while (nr_cases--)
    {
        scanf("%d%d", &P, &N);
        init();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < P; j++)
                scanf("%d", &S[i][j]);

        solve(S, mask, 0);
        printf("%d\n", P - maxsp);
    }
#ifdef LOCAL
    printf("\nTime used = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
    printf("****** END ******\n");
#endif
    return 0;
}