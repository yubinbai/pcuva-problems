#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int a, k = 0;
    while ((cin >> a) && (a != -1))
    {
        if (k) cout << endl;
        vector<int> v;
        v.push_back(a);
        while ((cin >> a) && (a != -1)) v.push_back(a);
        int maxL = 1, S[v.size()];
        for (int i = 0; i < v.size(); i++)
        {
            S[i] = 1;
            for (int j = 0; j < i; j++)
                if (v[j] >= v[i])
                    S[i] = max(S[i], S[j] + 1);
            maxL = max(maxL, S[i]);
        }
        printf("Test #%d:\n", ++k);
        printf("  maximum possible interceptions: %d\n", maxL);
    }
    return 0;
}