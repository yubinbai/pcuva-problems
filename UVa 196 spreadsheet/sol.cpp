#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<string>
#define MAXN 1010
#define MARK -2147483645

using namespace std;
int sheet[MAXN][MAXN];
int row, col;
string str;
string formula[MAXN][MAXN];


int dfs(int r, int c)
{
    if (sheet[r][c] != MARK) return sheet[r][c];
    if (sheet[r][c] == MARK)
    {
        int m_row, m_col;
        char temp[MAXN];
        string str = formula[r][c];

        sheet[r][c] = 0;

        for (int i = 1, pos = 0; i <= str.size() + 1; ++i)
        {
            if (str[i] == '+' || i == str.size())
            {
                temp[pos] = '\0';
                m_row = 0, m_col = 0;
                int k;
                for (k = 0; k < strlen(temp) && !isdigit(temp[k]); ++k)
                {
                    m_col = m_col * 26 + temp[k] - 'A' + 1;
                }
                for ( ; k < strlen(temp); ++k)
                {
                    m_row = m_row * 10 + temp[k] - '0';
                }
                pos = 0;
                sheet[r][c] += dfs(m_row, m_col);
            }
            else
            {
                temp[pos++] = str[i];
            }
        }
        return sheet[r][c];
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &col, &row);

        memset(sheet, 0, sizeof(sheet));

        int val;
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {

                cin >> str;

                if (str[0] == '=')
                {
                    sheet[i][j] = MARK;
                    formula[i][j] = str;
                }
                else
                {
                    val = atoi(str.c_str());
                    sheet[i][j] = val;
                }
            }
        }
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j) if (sheet[i][j] == MARK)
                {
                    dfs(i, j);
                }
        }

        for (int i = 1; i <= row; ++i)
        {
            printf("%d", sheet[i][1]);
            for (int j = 2; j <= col; ++j)
            {
                printf(" %d", sheet[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
