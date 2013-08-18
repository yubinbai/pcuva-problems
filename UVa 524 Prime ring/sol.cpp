#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return 0;
    return 1;
}

int n, A[50], isPrime[50], visited[50];
void dfs(int cur)
{
    if (cur == n && isPrime[A[0] + A[n - 1]])
    {
        for (int i = 0; i < n; i++)
        {
            if (i != 0) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    }
    else
        for (int i = 2; i <= n; i++)
            if (!visited[i] && isPrime[i + A[cur - 1]])
            {
                A[cur] = i;
                visited[i] = 1;
                dfs(cur + 1);
                visited[i] = 0;
            }
}

int main()
{
    int caseNumber = 0;
    while (scanf("%d", &n) == 1 && n > 0)
    {
        if (caseNumber > 0)
            printf("\n");
        printf("Case %d:\n", ++caseNumber);
        for (int i = 2; i <= n * 2; i++)
            isPrime[i] = is_prime(i);
        memset(visited, 0, sizeof(visited));
        A[0] = 1;
        dfs(1);
    }
    return 0;
}
