#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

#define N (16)
#define M (128)

int nSwitch, switchEffect[M], nLight;
int nSteps[1 << N];

int dfs()
{
    queue<int> q;
    q.push(~ -(1 << nLight));
    memset(nSteps, -1, sizeof(nSteps));
    nSteps[~ -(1 << nLight)] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        if (p)
        {
            for (int i = 0; i < nSwitch; ++i)
            {
                int newP = p ^ switchEffect[i];
                if (nSteps[newP] == -1)
                {
                    nSteps[newP] = nSteps[p] + 1;
                    q.push(newP);
                }
            }
        }
        else
            return nSteps[p];
    }
    return -1;
}

int main()
{
    int nCase;
    scanf("%d", &nCase);
    for (int caseI = 0; caseI < nCase; ++caseI)
    {
        int t;
        // in
        scanf("%d %d", &nLight, &nSwitch);
        for (int i = 0; i < nSwitch; ++i)
        {
            switchEffect[i] = 0;
            for (int j = 0; j < nLight; ++j)
            {
                scanf("%d", &t);
                switchEffect[i] <<= 1;
                switchEffect[i] |= t;
            }
        }
        // solve
        t = dfs();
        if (t == -1)
            printf("Case %d: IMPOSSIBLE\n", caseI + 1);
        else
            printf("Case %d: %d\n", caseI + 1, t);
    }
    return 0;
}