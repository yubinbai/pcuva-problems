#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int arr[100002];

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        long long ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            ans += abs(arr[i]);
            arr[i + 1] += arr[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
