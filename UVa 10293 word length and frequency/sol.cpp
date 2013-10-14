#include <iostream>
#include <string>
using namespace std;
int data[50];
void init()
{
    for (int i = 0; i < 50; ++i)
        data[i] = 0;
}
int main()
{
    char ch, prev;
    int i, j, len;
    bool flag = false;
    while (!cin.eof())
    {
        init();
        do
        {
            len = 0;
            ch = cin.get();
            prev = ch;
            if (cin.eof())
            {
                flag = true;
                break;
            }
            while (ch != ' ' && ch != '?' && ch != '!' && ch != ',' && ch != '.')
            {
                if (ch == '#') break;
                if (ch == '\'' || ch == '-' || ch == '\n')
                {
                    if (ch == '\n' && prev != '-')
                    {
                        break;
                    }
                    prev = ch;
                    ch = cin.get();
                    continue;
                }
                ++len;
                prev = ch;
                ch = cin.get();
            }
            ++data[len];
        }
        while (ch != '#');
        if (flag) break;
        for (i = 1; i < 50; ++i)
        {
            if (data[i] != 0)
                cout << i << " " << data[i] << endl;
        }
        cout << endl;
    }
    return 0;
}