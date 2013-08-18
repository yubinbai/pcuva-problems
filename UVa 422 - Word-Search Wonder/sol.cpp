//c++ solution

#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 101

using namespace std;

int n;
char mat[MAX][MAX], p[MAX];

bool traversex(int i, int j, char p[], int &ix, int &jx, int incx, int incy)
{
    int l = strlen(p);
    ix = i; jx = j;
    for (int i1 = i, j1 = j, k = 0; k < l; i1 += incx, j1 += incy, k++)
    {
        if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= n) return false;
        if (p[k] != mat[i1][j1]) return false;
        else
        {
            ix = i1;
            jx = j1;
        }
    }
    return true;
}
void search()
{
    int ti, tj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (p[0] == mat[i][j])
            {
                if (traversex(i, j, p, ti, tj, 1, 0))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, -1, 0))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, 0, 1))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, 0, -1))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, 1, 1))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, -1, -1))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, 1, -1))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
                if (traversex(i, j, p, ti, tj, -1, 1))
                {
                    cout << i + 1 << "," << j + 1 << " " << ti + 1 << "," << tj + 1 << endl;
                    return;
                }
            }

    cout << "Not found" << endl;
}
int main()
{

    cin >> n;


    for (int i = 0; i < n; i++)
        cin >> mat[i];

    for (;;)
    {
        cin >> p;
        if (strcmp(p, "0") == 0)
            break;
        else
            search();
    }

    return 0;
}