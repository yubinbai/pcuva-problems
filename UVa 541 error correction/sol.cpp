#include<iostream>
using namespace std;
int main()
{
    for (;;)
    {
        int n = 0, i = 0, j = 0, mat[100][100] = {0}, rowsum[100] = {0},
                colsum[100] = {0}, r = 0, c = 0, row = 0, col = 0;
        cin >> n;
        if (n == 0)
            break;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                rowsum[i] += mat[i][j];
            if (rowsum[i] % 2 != 0)
            {
                r++;
                row = i;
            }
        }
        for (j = 0; j < n; j++)
        {
            for (i = 0; i < n; i++)
                colsum[j] += mat[i][j];
            if (colsum[j] % 2 != 0)
            {
                c++;
                col = j;
            }
        }
        if (r == 0 && c == 0)
            cout << "OK" << endl;
        if (r == 1 && c == 1)
            cout << "Change bit (" << row + 1 << "," << col + 1 << ")" << endl;
        if (r > 1 || c > 1)
            cout << "Corrupt" << endl;
    }
    return 0;
}