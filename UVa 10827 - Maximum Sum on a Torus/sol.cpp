#include <algorithm>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
#define FOR(ii, i0, in) for((ii)=(i0); (ii)<(in); ++(ii))
#define FOR2d(ii, jj, i0, j0, in, jn) FOR(ii, i0, in) FOR(jj, j0, jn)

int main()
{
    int T, N, i, j, w, v;
    scanf("%d", &T);
    while (T-- && scanf("%d", &N) == 1)
    {
        int a[2 * N][2 * N], prefixSum[2 * N][2 * N], maxSum = 0;
        memset(prefixSum, 0, sizeof prefixSum);
        FOR2d(i, j, 0, 0, N, N)
        {
            scanf("%d", &a[i][j]);
            a[i][j + N] = a[i + N][j] = a[i + N][j + N] = a[i][j];
        }
        N *= 2;
        FOR2d(i, j, 0, 0, N, N)
        prefixSum[i][j] = a[i][j] + (i ? prefixSum[i - 1][j] : 0);
        FOR2d(w, i, 1, 0, N / 2 + 1, N - w)
        FOR(j, 0, N / 2)
        {
            int kadaneSum = 0, cols = 0;
            FOR(v, j, j + N / 2)
            {
                int colSum = prefixSum[i + w][v] - prefixSum[i][v];
                kadaneSum = (kadaneSum >= 0 ? kadaneSum : 0) + colSum ;
                maxSum = max(kadaneSum, maxSum);
            }
        }
        printf("%d\n", maxSum);
    }
    return 0;
}