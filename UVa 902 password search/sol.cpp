#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <list>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<int, int> mii;
int main()
{
    int n;
    string s;
    while (cin >> n >> s)
    {
        map<string, int> fre;
        for (int i = 0; i < s.length() - n; i++)
        {
            fre[s.substr(i, n)]++;
        }
        int max = -1; string ts;
        for (map<string, int>::iterator it = fre.begin(); it != fre.end(); it++)
        {
            if (it->second > max)
            {
                max = it->second; ts = it->first;
            }
        }
        cout << ts << endl;
    }
    return 0;
}