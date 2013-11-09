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
    while (true)
    {
        int N, i;
        cin >> N;
        if (N == 0)
            break;
        map<vector<int>, int> Map;
        map<vector<int>, int>::iterator it;
        int maxm = 1;
        while (N--)
        {
            vector<int> V(5);
            FOI(i, 0, 4)
            cin >> V[i];
            sort(V.begin(), V.end());
            Map[V] += 1;
            maxm = max(maxm, Map[V]);
        }
        int tot = 0;
        for (it = Map.begin(); it != Map.end(); it++)
        {
            if (maxm == (*it).second)
                tot += (*it).second;
        }
        cout << tot << endl;
    }
    return 0;
}
