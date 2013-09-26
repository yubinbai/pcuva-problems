#include <iostream>
#include <cstdlib>
using namespace std;
const int n_max = 10000, k_max = 100;
int seq[n_max];
bool memo[2][k_max];
bool calculate_memo(int n, int k)
{
    for (int i = 0; i < k; i++)
        memo[0][i] = false;
    memo[0][seq[0] % k] = true;
    for (int i = 1; i < n; i++)
    {
        int prev = (i - 1) % 2, curr = i % 2;
        for (int j = 0; j < k; j++)
        {
            int r = seq[i] % k;
            memo[curr][j] = memo[prev][(j - r + k) % k] ||
                            memo[prev][(j + r) % k];
        }
    }
    return memo[(n - 1) % 2][0];
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            seq[i] = abs(j);
        }
        cout << ((calculate_memo(n, k)) ? "Divisible\n" : "Not divisible\n");
    }
    return 0;
}