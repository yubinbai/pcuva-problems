#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
int matrix[maxn][maxn];
int width, height;

inline void input()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            cin >> matrix[i][j];

            matrix[i][j] = 1 - matrix[i][j];
        }
    }
}

int max_sum(int *b, int *matrix, int len_colu)
{
    int C_sum = 0;
    int temp = 0;
    for (int i = 0; i < height; i++) b[i] += matrix[i];

    for (int i = 0; i < height; i++)
    {
        if (b[i] < len_colu)
        {
            temp = 0;
            continue;
        }
        temp += b[i];
        if (temp > C_sum) C_sum = temp;
    }
    return C_sum;
}

void solve()
{
    int maxSum = 0, b[maxn];
    int temp = 0;
    for (int i = 0; i < width; i++)
    {
        memset(b, 0, sizeof(b));
        for (int j = i; j < width; j++)
        {

            temp = max_sum(b, matrix[j], j - i + 1);
            maxSum = max(maxSum, temp);
        }
    }
    cout << maxSum << endl;
}

int main()
{
    while (cin >> width >> height && (width || height))
    {
        input();
        solve();
    }
    return 0;
}
