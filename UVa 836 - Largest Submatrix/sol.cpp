#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
int matrix[maxn][maxn];
int matrix_temp[maxn];
int width, height;

inline void input()
{
    char str[maxn][maxn], tt[maxn];
    int tempInt, flag = 1, kk = 0;
    width = height = 0;

    while (gets(tt) && tt[0])
    {
        for (height = 0; tt[height]; height++)  matrix[width][height] = tt[height] - '0';
        width++;
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

void solve(int count1)
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
    if (count1 == 0) cout << maxSum << endl;
    else cout << endl << maxSum << endl;
}

int main()
{
    int testCase;
    while (cin >> testCase)
    {
        getchar();
        getchar();
        for (int i = 0; i < testCase; i++)
        {
            input();
            solve(i);
        }
    }

    return 0;
}