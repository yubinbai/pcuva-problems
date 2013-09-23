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
struct Switch
{
    bool S;
    int V;
};
int main()
{
    for (int t = 1; ; t++)
    {
        int N, M, C;
        cin >> N >> M >> C;
        if ( N == 0 && M == 0 && C == 0 )
            break;
        int curr = 0, maxm = -1;
        bool fuse = false;
        Switch swit[N];
        int i, j;
        FOI(i, 0, N - 1)
        {
            cin >> swit[i].V;
            swit[i].S = false;
        }
        while ( M-- )
        {
            int P;
            cin >> P;
            --P;
            swit[P].S = !swit[P].S;
            if ( !swit[P].S )
                curr -= swit[P].V;
            else
                curr += swit[P].V;
            maxm = max(curr, maxm);
            if ( maxm > C )
                fuse = true;
        }
        cout << "Sequence " << t << "\n";
        if ( fuse )
            cout << "Fuse was blown.\n";
        else
        {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << maxm << " amperes.\n";
        }
        cout << "\n";
    }
    return 0;
}