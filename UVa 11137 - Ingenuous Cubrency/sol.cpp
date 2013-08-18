#include<iostream>
using namespace std;
#define MAX 10000

int cube(int i)
{
    return i * i * i;
}
unsigned long long int dp[MAX];

int main()
{
    for (int i = 1; i < MAX; i++ )
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 1; i < 22; i++)
    {
        int cube_of_i = cube(i);
        for (int j = cube_of_i; j < MAX; j++)
        {
            dp[j] = dp[j - cube_of_i] + dp[j];

        }
    }

    int i;
    while (cin >> i)
    {
        cout << dp[i] << endl;
    }

    return 0;
}