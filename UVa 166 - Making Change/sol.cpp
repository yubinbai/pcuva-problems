#include "stdio.h"
#include <algorithm>
#include <cstring>
#include <limits>
#include <stdlib.h>

using namespace std;

#define FOR(k,a,b) for(int k=(a); k < (b); ++k)
#define pb push_back

typedef unsigned long long ull;

int V[] = { 1, 2, 4, 10, 20, 40};
int C[6];
int N = 6;

const int SIZE_DP = 1000;
int dp[SIZE_DP];
int dpNext[SIZE_DP];

int dpShop[SIZE_DP];
int dpShopNext[SIZE_DP];

int main()
{
    int d1, d2;
    while (true)
    {
        int ok = 0;
        FOR(i, 0, N)
        {
            scanf("%d", &C[i]);
            ok |= C[i];
        }

        if (!ok)
            break;

        int d1, d2;
        float f;
        scanf("%f", &f);
        f += 0.001;
        int target = (int) ( f * 100);
        target /= 5;


        fill(dp, dp + SIZE_DP, numeric_limits<int>::max());
        fill(dpNext, dpNext + SIZE_DP, numeric_limits<int>::max());
        fill(dpShop, dpShop + SIZE_DP, numeric_limits<int>::max());
        fill(dpShopNext, dpShopNext + SIZE_DP, numeric_limits<int>::max());
        dpNext[0] = dp[0] = 0;
        dpShopNext[0] = dpShop[0] = 0;

        FOR(i, 0, N)
        {
            for (int amt = 0; amt < SIZE_DP; ++amt)
            {
                if (dp[amt] == numeric_limits<int>::max())
                    continue;

                for (int j = 1; j <= C[i] && amt + j * V[i] < SIZE_DP; ++j)
                {
                    dpNext[amt + j * V[i]] =
                        min(dpNext[amt + j * V[i]],
                            dp[amt] + j);
                }
            }

            memcpy(dp, dpNext, sizeof(dp));

            for (int amt = 0; amt < SIZE_DP; ++amt)
            {
                if (dpShop[amt] == numeric_limits<int>::max())
                    continue;

                for (int j = 1; amt + j * V[i] < SIZE_DP; ++j)
                {
                    dpShopNext[amt + j * V[i]] =
                        min(dpShopNext[amt + j * V[i]],
                            dpShop[amt] + j);
                }
            }

            memcpy(dpShop, dpShopNext, sizeof(dpShop));

        }


        int minCoinsUsed = numeric_limits<int>::max();

        for (int amt = target; amt < SIZE_DP; ++amt)
        {
            int toGive = dp[amt];
            int toGet = dpShop[amt - target];

            if (toGive == numeric_limits<int>::max() || toGet == numeric_limits<int>::max())
                continue;

            int coinsUsed = toGive + toGet;
            minCoinsUsed = min(minCoinsUsed, coinsUsed);
        }
        printf("%3d\n", minCoinsUsed);
    }

    return 0;
}