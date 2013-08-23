#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;
#define D(x) cout << __LINE__ <<"   "<<#x"  is  " << x << endl
int g[30][30];
int m[30][30];
int main()
{
    int N;
    string f;
    while (scanf("%d", &N) == 1 && N)
    {
        getline(cin, f);
        for (int i = 0; i < 30; ++i)
        {
            for (int j = 0; j < 30; ++j)
            {
                m[i][j] = g[i][j] = INT_MAX / 2;
            }
        }
        for (int i = 0; i < 30; ++i) m[i][i] = g[i][i] = 0;
        for (int i = 0; i < N; ++i)
        {
            char a, b, c, d;
            getline(cin, f);
            int t;
            sscanf(f.c_str(), "%c %c %c %c %d", &a, &b, &c, &d, &t);
            if (a == 'Y')
            {
                g[c - 65][d - 65] = min(t, g[c - 65][d - 65]);
                if (b == 'B')
                {
                    g[d - 65][c - 65] = min(t, g[d - 65][c - 65]);
                }
            }
            else
            {
                m[c - 65][d - 65] = min(t, m[c - 65][d - 65]);
                if (b == 'B')
                {
                    m[d - 65][c - 65] = min(t, m[d - 65][c - 65]);
                }
            }
        }
        getline(cin, f);
        char me, mig;
        sscanf(f.c_str(), "%c %c", &me, &mig);
        for (int k = 0; k < 30; ++k)
        {
            for (int i = 0; i < 30; ++i)
            {
                for (int j = 0; j < 30; ++j)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
                }
            }
        }
        int ma = INT_MAX / 2;
        vector<char> s;
        s.clear();
        for (int i = 'Z'; i >= 'A'; --i)
        {
            if (ma > ( g[me - 65][i - 65] + m[mig - 65][i - 65]) )
            {
                s.clear();
                ma = g[me - 65][i - 65] + m[mig - 65][i - 65];
                s.push_back(i);
            }
            else if (ma == ( g[me - 65][i - 65] + m[mig - 65][i - 65]) )
            {
                s.push_back(i);
            }
        }
        sort(s.begin(), s.end());
        if (ma != INT_MAX / 2)
        {
            printf("%d", ma);
            for (int i = 0; i < s.size(); ++i) printf(" %c", s[i]);
            puts("");
        }
        else
            puts("You will never meet.");
    }
}
