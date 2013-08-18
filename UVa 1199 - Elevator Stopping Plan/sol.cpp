#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int M = 30001;
bool ind[M];
int n;
typedef vector<int> vi;
vi solution(M), tempSolution(M);
int solve(int t)
{
    tempSolution.clear();
    int i, j, num = 0;
    i = t / 20 + 2;
    while (i <= n)
    {
        while (i <= n && ind[i] == false)
            i++;
        tempSolution.push_back(i);
        if ((i - 1) * 4 + 10 * num > t)
            return 0;
        j = (t - 10 * num + 20 * i + 4) / 24;
        i = (t - 10 * num + 16 * j + 4) / 20 + 1;
        num++;
    }
    solution = tempSolution;
    return 1;
}
int main()
{
    int i, j, min, max, mid, t;
    while (scanf("%d", &t) && t)
    {
        memset(ind, false, sizeof(ind));
        n = -1;
        for (i = 0; i < t; i++)
        {
            scanf("%d", &j);
            if (j > n)  n = j;
            ind[j] = true;
        }
        min = 0; max = 14 * (n - 1);
        while (min < max - 1)
        {
            mid = (min + max) / 2;
            if (solve(mid)) max = mid;
            else  min = mid;
        }
        printf("%d\n", max); // need solution too
        int size = solution.size();
        printf("%d ", size);
        for (int i = 0; i < size - 1; ++i)
        {
            printf("%d ", solution[i]);
        }
        printf("%d\n", solution[size - 1]);

    }
    return 0;
}
