#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10005
int n;
int a[MAX];
int list1[MAX], list2[MAX];
int ans1[MAX], ans2[MAX];
inline int min(int a, int b)
{
    return a < b ? a : b;
}
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int binarySearch(int left, int right, int cur, int *b)
{
    while (left < right)
    {
        int mid = (left + right) / 2;
        if ( b[mid] < cur ) left = mid + 1;
        else right = mid;
    }
    return left;
}
int main()
{
    int i;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        int index1 = 0, index2 = 0;
        int tempindex1 = 0, tempindex2 = 0;
        for (i = 1; i <= n; ++i)
        {
            tempindex1 = binarySearch(1, index1 + 1, a[i], list1);
            tempindex2 = binarySearch(1, index2 + 1, a[n - i + 1], list2);
            index1 = max(tempindex1, index1);
            index2 = max(tempindex2, index2);
            ans1[i] = tempindex1;
            ans2[n - i + 1] = tempindex2;
            list1[tempindex1] = a[i];
            list2[tempindex2] = a[n - i + 1];
        }
        int ans = 1;
        for (i = 1; i <= n; ++i)
            ans = max(ans, min(ans1[i], ans2[i]) * 2 - 1);
        printf("%d\n", ans);
    }
    return 0;
}