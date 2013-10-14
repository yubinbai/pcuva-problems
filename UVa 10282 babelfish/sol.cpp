#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    map<string, string> dictionary;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;
        size_t delim = line.find(' ');
        dictionary[line.substr(delim + 1)] = line.substr(0, delim);
    }
    while (cin >> line)
    {
        if (dictionary.count(line))
            cout << dictionary[line] << endl;
        else
            cout << "eh" << endl;
    }
    return 0;
}