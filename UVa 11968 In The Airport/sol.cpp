#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<int, int> mii;
int pc[1001], pd[1001];
#define EPS 1e-5
int main()
{
    int TC, N, M, K, t;
    int CC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> M >> K;
        double ps = 0;
        for (int i = 0; i < M; i++)
        {
            cin >> pc[i];
            ps += pc[i];
        }
        for (int i = 0; i < K; i++)
        {
            cin >> pd[i];
            ps += pd[i];
        }
        for (int i = 0; i < N - M - K; i++)
        {
            cin >> t;
            ps += t;
        }
        double avg_p = ps / N;
        int cnp, dnp;
        double cdp = 1e11, ddp = 1e11;
        for (int i = 0; i < M; i++)
        {
            if ( (abs(pc[i] - avg_p) < cdp - EPS) ||
                    ( (abs(pc[i] - avg_p) < cdp + EPS) && (pc[i] < cnp))
               )
            {
                cdp = abs(pc[i] - avg_p);
                cnp = pc[i];
            }
        }
        for (int i = 0; i < K; i++)
        {
            if ( (abs(pd[i] - avg_p) < ddp - EPS) ||
                    ( (abs(pd[i] - avg_p) < ddp + EPS) && (pd[i] < dnp))
               )
            {
                ddp = abs(pd[i] - avg_p);
                dnp = pd[i];
            }
        }
        printf("Case #%d: %d %d\n", CC++, cnp, dnp);
    }
    return 0;
}
