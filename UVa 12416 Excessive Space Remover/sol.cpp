#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        double action = 0.0, space = 0.0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ') space += 1.0;
            else
            {
                action = max(action, log2(space));
                space = 0;
            }
        }
        cout << ceil(action) << endl;
    }
    return 0;
}