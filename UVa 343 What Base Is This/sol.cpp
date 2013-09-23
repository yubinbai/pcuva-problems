#include <map>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string Alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, int> Map;
int calc(string S, int B)
{
    int mul = 1;
    int val = 0;
    for (int i = S.length() - 1; i >= 0; i--)
    {
        val += (Map[S[i]] * mul);
        mul *= B;
    }
    return val;
}
int maxm(string S)
{
    int B = 0;
    for (int i = 0; i < S.length(); i++)
    {
        B = max(B, Map[S[i]]);
    }
    return max(2, B + 1);
}
int main()
{
    for (int i = 0; i < Alpha.length(); i++)
    {
        Map[(char)Alpha[i]] = i;
    }
    string A, B;
    while (cin >> A >> B)
    {
        int baseA, baseB;
        int aSta = maxm(A), bSta = maxm(B);
        bool flag = false;
        for (baseA = aSta; baseA <= 36; baseA++)
        {
            int valA = calc(A, baseA);
            for (baseB = bSta; baseB <= 36; baseB++)
            {
                int valB = calc(B, baseB);
                if (valA == valB)
                {
                    cout << A << " (base " << baseA << ") = " << B << " (base " << baseB << ")\n";
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag)
            cout << A << " is not equal to " << B << " in any base 2..36\n";
    }
    return 0;
}