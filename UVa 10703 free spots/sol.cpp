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
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
int main()
{
    while ( true )
    {
        int W, H, N;
        scanf("%d%d%d", &W, &H, &N);
        if ( W == 0 && H == 0 && N == 0 )
            break;
        bool mat[W][H];
        int i, j;
        memset(mat, false, sizeof(mat) );
        while ( N-- )
        {
            int X1, Y1, X2, Y2;
            scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
            FOI(i, min(X1, X2) - 1, max(X1, X2) - 1)
            FOI(j, min(Y1, Y2) - 1, max(Y1, Y2) - 1)
            mat[i][j] = true;
        }
        int cnt = 0;
        FOI(i, 0, W - 1)
        FOI(j, 0, H - 1)
        if ( !mat[i][j] )
            cnt++;
        if ( cnt == 0 )
            printf("There is no empty spots.\n");
        else if ( cnt == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", cnt);
    }
    return 0;
}