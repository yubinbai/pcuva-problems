#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
int main()
{
    string word;
    vector<string> dict;
    while (cin >> word)
        dict.push_back(word);
    sort(dict.begin(), dict.end());
    for (int i = 0; i < dict.size(); i++)
    {
        if (dict[i].length() == 1) continue;
        for (int j = 1; j < dict[i].length(); j++)
        {
            string word1 = dict[i].substr(0, j);
            string word2 = dict[i].substr(j, dict[i].length() - j);
            if (binary_search(dict.begin(), dict.end(), word1) &&
                    binary_search(dict.begin(), dict.end(), word2) )
            {
                cout << dict[i] << endl;
                break;
            }
        }
    }
    return 0;
}