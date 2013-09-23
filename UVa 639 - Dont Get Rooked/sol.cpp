#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void rooking(char **m, int **mi, int &max, int N, int i, int j, int c);
void mark(char **m, int **mi, int i, int j, int d, int N);
int main()
{
    int N;
    cin >> N;
    cin.get();
    while (N != 0)
    {
        char **m = new char*[N];
        int **mi = new int*[N];
        for (int i = 0; i < N; ++i)
        {
            m[i] = new char[N];
            mi[i] = new int[N];
            memset(mi[i], 0, sizeof(int)*N);
            scanf("%s", m[i]);
        }
        int max = 0;
        rooking(m, mi, max, N, -1, 0, 0);
        cout << max << endl;
        cin >> N;
        cin.get();
    }
}
void rooking(char **m, int **mi, int &max, int N, int i, int j, int c)
{
    if (c > max) max = c;
    int ni = (i + 1) % N;
    int nj = (i + 1 == N) ? j + 1 : j;
    while (nj < N)
    {
        if (m[ni][nj] != 'X' && mi[ni][nj] == 0)
        {
            //check rook in i, j
            mark(m, mi, ni, nj, 1, N);
            rooking(m, mi, max, N, ni, nj, c + 1);
            //uncheck
            mark(m, mi, ni, nj, -1, N);
        }
        ni = (ni + 1) % N;
        nj = (ni == 0) ? nj + 1 : nj;
    }
}
int di[] = { -1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};
void mark(char **m, int **mi, int i, int j, int d, int N)
{
    mi[i][j] += d;
    for (int k = 0; k < 4; ++k)
    {
        int ni = i + di[k];
        int nj = j + dj[k];
        while (ni >= 0 && nj >= 0 && ni < N && nj < N && m[ni][nj] != 'X')
        {
            mi[ni][nj] += d;
            ni += di[k];
            nj += dj[k];
        }
    }
}
