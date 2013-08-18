#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

const int MAXN = 10010;
int stack[MAXN];
int d1[MAXN], d2[MAXN];
int a[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        
        int top = 0;
        stack[0] = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > stack[top])
                stack[++top] = a[i];
            else
            {
                int low = 1, high = top;
                while (low <= high)
                {
                    int mid = (low + high) >> 1;
                    if (a[i] > stack[mid])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                stack[low] = a[i];
            }
            d1[i] = top;
        }

        top = 0;
        stack[0] = INT_MIN;
        for (int i = n; i >= 1; --i)
        {
            if (a[i] > stack[top])
                stack[++top] = a[i];
            else
            {
                int low = 1, high = top;
                while (low <= high)
                {
                    int mid = (low + high) >> 1;
                    if (a[i] > stack[mid])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                stack[low] = a[i];
            }
            d2[i] = top;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (ans < min(d1[i], d2[i]))
                ans = min(d1[i], d2[i]);
        
        printf("%d\n", 2 * ans - 1);
    }
    return 0;
}