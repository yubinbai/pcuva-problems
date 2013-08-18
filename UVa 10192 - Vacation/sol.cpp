#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
const int kMaxn(107);

int d[kMaxn][kMaxn];

int main()
{
    int T(0);
    string a, b;
    while (getline(cin, a) && a != "#")
    {
        getline(cin, b);
        a.insert(0, " ");
        b.insert(0, " ");

        d[0][0] = d[1][0] = d[0][1] = 0;
        for (int i = 1; i < a.size(); i++)
            for (int j = 1; j < b.size(); j++)
                if (a[i] == b[j])
                    d[i][j] = d[i - 1][j - 1] + 1;
                else
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);

        T++;
        printf("Case #%d: you can visit at most %d cities.\n", T, d[a.size() - 1][b.size() - 1]);
    }

    return 0;
}