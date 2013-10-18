#include <iostream>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

int main()
{

    int n, m, q, caseN = 0;
    int v[1000];
    while (cin >> n && n != 0)
    {
        caseN++;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v, v + n);
        cin >> m;
        cout << "Case " << caseN << ":" << endl;
        for (int c = 0; c < m; c++)
        {
            cin >> q;
            int b, lb = 0x3f3f3f3f;
            int i = 0, j = n - 1;
            while (i != j)
            {
                b = v[i] + v[j];
                if (v[i] + v[j] < q)
                {
                    i++;
                }
                else if (v[i] + v[j] > q)
                {
                    j--;
                }
                else
                {
                    lb = b;
                    break;
                }
                if (abs(b - q) < abs(lb - q))
                {
                    lb = b;
                }
            }
            cout << "Closest sum to " << q << " is " << lb << "." << endl;
        }
    }
    return 0;
}