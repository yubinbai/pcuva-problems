#include<iostream>
#include<cstdio>
using namespace std;

int n;
int m;
int a[10];
int s[10000001];

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
            s[i] = 0;
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int v = i - a[j];
                if (v < 0) continue;
                if (s[v] == 0) s[i] = 1;
            }
        }
        if (s[n])
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}