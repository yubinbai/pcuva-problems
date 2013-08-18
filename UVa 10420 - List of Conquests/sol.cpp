#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

int main()
{
    map <string, int> hashMap;
    map <string, int>::iterator it;

    int t;
    string s, spare;
    cin >> t;

    while (t--)
    {
        cin >> s;
        getline(cin, spare);

        if (hashMap.find(s) != hashMap.end())
            hashMap[s]++;
        else
            hashMap[s] = 1;

    }
    for (it = hashMap.begin() ; it != hashMap.end() ; it++)
        cout << (*it).first << " " << (*it).second << endl;

    return 0;
}