#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef unsigned long long int ULL;
using namespace std;
int coinNum, sum, pos;
ULL coin[105], dp[100005];
/////////////////////////////
void input()
{
    sum = 0;
    for (int i = 1; i <= coinNum; i++)
    {
        cin >> coin[i];
        sum += coin[i];
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[sum] = 1;
    for (int i = 1; i <= coinNum; i++)
    {
        for (int k = sum; k >= coin[i]; k--)
        {
            if (dp[k - coin[i]])
                dp[k] = 1;
        }
    }
    //search
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[j])
        {
            pos = j;
            break;
        }
    }
    cout << sum - 2 * pos << endl;
}
/////////////////////////////
int main()
{
    int testCase;
    while (cin >> testCase)
    {
        while (testCase--)
        {
            cin >> coinNum;
            input();
            solve();
        }
    }
    //system("pause");
    return 0;
}