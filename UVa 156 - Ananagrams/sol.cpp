#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Forn(i, n) For(i, 0, n)
#define Foreach(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)

using namespace std;

string &lowercaseString(string &str)
{
    Foreach(it, str)
    *it = tolower(*it);
    return str;
}

bool anagram(string str1, string str2)
{
    lowercaseString(str1);
    lowercaseString(str2);
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

int main()
{
    string input;
    vector<string> strs;
    while (cin >> input && input != "#")
    {
        strs.push_back(input);
    }
    vector<int> res(strs.size(), 0);

    Forn(i, strs.size())
    if (!res[i])
        Forn(j, strs.size())
        if (i != j)
            if (anagram(strs[i], strs[j]))
                res[i] = res[j] = 1;

    vector<string> output;
    Forn(i, res.size())
    if (!res[i])
        output.push_back(strs[i]);

    sort(output.begin(), output.end());
    Foreach(it, output)
    cout << *it << endl;
    return 0;
}