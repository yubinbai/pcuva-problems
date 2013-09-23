#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
void carry(vector < int > &out, int base)
{
    for (int i = out.size() - 1; i > 0; i--)
    {
        out[i - 1] += out[i] / base;
        out[i] %= base;
    }
    int tmp = out[0];
    while (tmp >= base)
    {
        out.insert(out.begin(), tmp / base);
        out[1] = tmp % base;
        tmp /= base;
    }
}
void trans(string s, int from, int to)
{
    vector < int > out;
    int  cut = (from == 26) ? ('a' - 1) : ('0');
    out.push_back(0);
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < out.size(); j++)
            out[j] *= from;
        int now = out.back() + s[i] - cut;
        out[out.size() - 1] = now;
        carry(out, to);
    }
    if (from == 10)
    {
        for (int i = 0; i < out.size(); i++)
            cout << char(out[i] + 'a' - 1);
        for (int i = 0; i < 22 - out.size(); i++)
            cout << ' ';
        int pos;
        bool printed = false;
        for (pos = 0; (s.length() - pos) % 3 != 0; pos++)
        {
            cout << s[pos];
            printed = true;
        }
        for ( ; pos < s.length(); pos += 3)
        {
            if (printed)
                cout << ',';
            cout << s[pos] <<
                 s[pos + 1] <<
                 s[pos + 2];
            printed = true;
        }
    }
    else
    {
        cout << s;
        for (int i = 0; i < 22 - s.length(); i++)
            cout << ' ';
        int pos;
        bool printed = false;
        for (pos = 0; (out.size() - pos) % 3 != 0; pos++)
        {
            cout << out[pos];
            printed = true;
        }
        for ( ; pos < out.size(); pos += 3)
        {
            if (printed)
                cout << ',';
            cout << out[pos] <<
                 out[pos + 1] <<
                 out[pos + 2];
            printed = true;
        }
    }
    cout << endl;
}
int main(void)
{
    while (true)
    {
        string tmp;
        cin >> tmp;
        if (tmp[0] == '*')
            break;
        else if (isalpha(tmp[0]))
            trans(tmp, 26, 10);
        else
            trans(tmp, 10, 26);
    }
    return 0;
}