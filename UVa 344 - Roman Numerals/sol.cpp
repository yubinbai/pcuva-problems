#include <iostream>
#include <map>
#define db(a) cout << #a << " = " << a << endl;
using namespace std;
int main()
{
    int n;
    string romanNumbers[] = {"c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    char rom[] = {'c', 'l', 'x', 'v', 'i'};
    int val[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
    while (cin >> n)
    {
        if (n == 0) break;
        map <char, int> mapA;
        for (int k = 1; k <= n; k++)
        {
            int m = k;
            string converted = "";
            for (int i = 0; i < 9; i++)
            {
                int div = m / val[i];
                m = m % val[i];
                for (int u = 0; u < div; u++)
                {
                    converted += romanNumbers[i];
                }
            }
            
            for (int i = 0; i < converted.size(); i++)
                mapA[converted[i]]++;
        }
        cout << n << ": ";
        for (int i = 4; i >= 0; i--)
        {
            if (i != 0)
                cout << mapA[rom[i]] << " " << rom[i] << ", ";
            else
                cout << mapA[rom[i]] << " " << rom[i];
        }
        cout << endl;
    }
    return 0;
}