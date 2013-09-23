#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
string decode(string &msg)
{
    reverse(msg.begin(), msg.end());
    char ascii = 0;
    string result;
    for (size_t i(0), size(msg.size()); i < size; ++i)
    {
        if (msg[i] == '1')
        {
            ascii = 100;
            ++i;
        }
        ascii += (msg[i++] - '0') * 10;
        ascii += (msg[i] - '0');
        result.push_back(ascii);
        ascii = 0;
    }
    return result;
}
string encode(const string &msg)
{
    char buff[80 * 3 + 1];
    size_t p(0);
    for (size_t i(0), size(msg.size()); i < size; ++i)
    {
        p += sprintf(buff + p, "%d", msg[i]);
    }
    string result(buff);
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    string line;
    while (getline(cin, line))
    {
        if (!line.size())
            cout << endl;
        else if (line[0] >= '0' && line[0] <= '9')
            cout << decode(line) << endl;
        else
            cout << encode(line) << endl;
    }
    return 0;
}