#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        if (z)cout << endl;
        cout << "Case " << z + 1 << ":" << endl;
        int base[36];
        for (int i = 0; i < 36; i++)cin >> base[i];
        int tt;
        cin >> tt;
        while (tt--)
        {
            int n, tmp;
            cin >> n;
            int ans[38], min = 900000;
            for (int i = 2; i <= 36; i++)
            {
                ans[i] = 0;
                tmp = n;
                while (tmp)
                {
                    ans[i] += base[tmp % i];
                    tmp /= i;
                }
                if (min > ans[i])min = ans[i];
            }
            cout << "Cheapest base(s) for number " << n << ":";
            for (int i = 2; i <= 36; i++)
            {
                if (ans[i] == min)cout << " " << i;
            }
            cout << endl;
        }
    }
}