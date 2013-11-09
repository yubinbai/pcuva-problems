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
#define PI acos(-1.0)
#define INF 1<<30
#define EPS 1e-9
#define sqr(x) (x)*(x)
int main()
{
    int T, t;
    char str[600];
    scanf("%d", &T);
    cin.getline(str, 600);
    FOI(t, 1, T)
    {
        int N;
        printf("Case %d:\n", t);
        scanf("%d", &N);
        cin.getline(str, 600);
        while (N--)
        {
            cin.getline(str, 600);
            int L = strlen(str);
            int i, j;
            bool space = false;
            FOI(i, 0, L - 1)
            {
                if (str[i] == ' ')
                {
                    if (!space)
                    {
                        printf("%c", str[i]);
                        space = true;
                    }
                    else
                        continue;
                }
                else
                {
                    printf("%c", str[i]);
                    space = false;
                }
            }
            printf("\n");
        }
        if (t < T)
            printf("\n");
    }
    return 0;
}
