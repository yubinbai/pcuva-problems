#include <cstdio>

const int n_max = 100, m_max = 100;
char grid[n_max][m_max + 1];

int largest_square(int m, int n, int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n)
        return 0;
    char sc = grid[r][c];
    int s;
    for (s = 3; ; s += 2)
    {
        int i_min = r - s / 2, i_max = r + s / 2,
            j_min = c - s / 2, j_max = c + s / 2;
        if (i_min < 0 || i_max >= m || j_min < 0 || j_max >= n)
            break;
        for (int j = j_min; j <= j_max; j++)
            if (grid[i_min][j] != sc || grid[i_max][j] != sc)
                goto done;
        for (int i = i_min + 1; i < i_max; i++)
            if (grid[i][j_min] != sc || grid[i][j_max] != sc)
                goto done;
    }
done:
    return s - 2;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, n, q;
        scanf("%d %d %d", &m, &n, &q);
        getchar();
        for (int i = 0; i < m; i++)
            gets(grid[i]);
        printf("%d %d %d\n", m, n, q);
        while (q--)
        {
            int r, c;
            scanf("%d %d", &r, &c);
            printf("%d\n", largest_square(m, n, r, c));
        }
    }
    return 0;
}