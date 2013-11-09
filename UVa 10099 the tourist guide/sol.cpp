#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
#define PI                acos(-1.0)
#define INF                1<<30
#define EPS                1e-9
#define sqr(x)        (x)*(x)
int main()
{
    for (int t = 1; ; t++)
    {
        int N, R;
        scanf("%d%d", &N, &R);
        if (N == 0 && R == 0)
            break;
        int mat[N][N];
        int i, j, k;
        FOI(i, 0, N - 1)
        FOI(j, 0, N - 1)
        mat[i][j] = 0;
        FOI(i, 1, R)
        {
            int C1, C2, P;
            scanf("%d%d%d", &C1, &C2, &P);
            --C1; --C2;
            mat[C1][C2] = P;
            mat[C2][C1] = P;
        }
        FOI(k, 0, N - 1)
        FOI(i, 0, N - 1)
        FOI(j, 0, N - 1)
        mat[i][j] = mat[j][i] = max(mat[i][j], min(mat[i][k], mat[k][j]));
        int S, D, T;
        scanf("%d%d%d", &S, &D, &T);
        --S; --D;
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", t, (int)ceil((double)T / (mat[S][D] - 1.0)));
    }
    return 0;
}
