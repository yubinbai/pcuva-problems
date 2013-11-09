#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 != len2)
        {
            cout << "No" << endl;
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < len1; j++)
        {
            if ((str1[j] == 'a' || str1[j] == 'e' || str1[j] == 'i' || str1[j] == 'o' || str1[j] == 'u') &&
                    (str2[j] == 'a' || str2[j] == 'e' || str2[j] == 'i' || str2[j] == 'o' || str2[j] == 'u') &&
                    (str1[j] != str2[j]))
            {
                cnt++;
                continue;
            }
            if (str1[j] == str2[j])
                cnt++;
        }
        if (cnt == len1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}