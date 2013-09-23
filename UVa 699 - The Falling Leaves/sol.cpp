#include <cstdio>
#include <cstring>
const int maxn = 199;
const int mid = 100;
int ans[maxn];
int left, right;    //the left and right boundary
int first;
int tree_dfs(int step)
{
    int x;
    scanf("%d", &x);
    if (first)
    {
        first = 0;
        if (x == -1)   return 0;
    }
    if (x > 0)
    {
        ans[mid + step] += x;
        if (mid + step < left)
            left = mid + step;
        if (mid + step >= right)
            right = mid + step + 1;
        tree_dfs(step - 1);
        tree_dfs(step + 1);
    }
    return 1;
}
int main()
{
    int itertest = 0;
    while (1)
    {
        first = 1;
        left = 100;
        right = 101;
        memset(ans, 0, sizeof(ans));
        if (!tree_dfs(0))   break;
        printf("Case %d:\n", ++itertest);
        for (int i = left; i < right; i++)
        {
            printf("%s", i == left ? "" : " ");
            printf("%d", ans[i]);
        }
        printf("\n\n");
    }
    return 0;
}