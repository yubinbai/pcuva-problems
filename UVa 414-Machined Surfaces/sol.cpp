#include<iostream>
#include<fstream>
using namespace std;
char m[30][30];
int main()
{
    int n, i, j, max, count, tot;
    while (cin >> n)
    {
        if (n == 0) return 0;
        cin.get();
        for (i = 0; i < n; i++) cin.getline(m[i], 26);
        max = 0; tot = 0;
        for (i = 0; i < n; i++)
        {
            count = 0;
            for (j = 0; m[i][j]; j++)
                if (m[i][j] == 'X') count++;
            if (max < count) max = count;
            tot += count;
        }
        cout << max *n - tot << endl;
    }

    return 0;
}