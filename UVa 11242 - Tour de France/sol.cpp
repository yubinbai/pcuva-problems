#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cassert>
using namespace std;

int main()
{
    bool first = true;
    int zero = 0;

    while (true)
    {
        int f, r, ft[101], rt[101];
        vector<double> ratios;

        cin >> f;
        if (f == 0) break;

        cin >> r;

        for (int i = 0; i < f; i++) cin >> ft[i];
        for (int i = 0; i < r; i++) cin >> rt[i];

        // outer loop on the longest
        for (int i = 0; i < f; i++)
            for (int j = 0; j < r; j++)
                ratios.push_back(((double) rt[j]) / ((double) ft[i]));

        sort(ratios.begin(), ratios.end());

        vector<double>::iterator it;
        double prev = ratios[0];
        double max_spread = 0;

        for (it = ratios.begin() + 1; it != ratios.end(); it++)
        {
            double spread = *it / prev;
            if (spread > max_spread) max_spread = spread;
            prev = *it;
        }

        printf("%.2f\n", max_spread);

        first = false;
    }

    return 0;
}
