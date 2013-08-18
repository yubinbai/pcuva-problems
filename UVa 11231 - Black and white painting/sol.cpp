#include <stdio.h>

int main()
{
    int n, m, c;
    while (1)
    {
        scanf("%d %d %d", &n, &m, &c);
        if (n == 0 && m == 0 && c == 0)
            break;
        int temp = (n - 7) * (m - 7);
        int ans = temp / 2;
        if (temp % 2 == 1 && c == 1)
            ans++;
        printf("%d\n", ans);

    }
    return 0;
}