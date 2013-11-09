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
typedef long long int64;
typedef unsigned long long uint64;
#define INF        1LL<<60
#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)
int main()
{
    int N;
    int i, j, k;
    cin >> N;
    int64 mat[N][N];
    FOI(i, 0, N - 1)
    mat[i][i] = 0;
    FOI(i, 0, N - 1)
    {
        FOI(j, 0, i - 1)
        {
            string str;
            cin >> str;
            if ( str == "x" )
            {
                mat[i][j] = INF;
                mat[j][i] = INF;
            }
            else
            {
                stringstream ss(str);
                ss >> mat[i][j];
                mat[j][i] = mat[i][j];
            }
        }
    }
    FOI(k, 0, N - 1)
    FOI(i, 0, N - 1)
    FOI(j, 0, N - 1)
    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    int64 gmax = 0;
    FOI(i, 0, N - 1)
    gmax = max(gmax, mat[0][i]);
    cout << gmax << endl;
    return 0;
}