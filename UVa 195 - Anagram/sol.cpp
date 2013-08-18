#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

bool compare (char a, char b)
{
    bool aIsLower = true, bIsLower = true;
    if (a >= 'A' && a <= 'Z')
        aIsLower = false;
    if (b >= 'A' && b <= 'Z')
        bIsLower = false;

    //Both are upper or lower case
    if (aIsLower && bIsLower)
        return a < b;
    if (!aIsLower && !bIsLower)
        return a < b;

    //a it's a lowercase
    if (aIsLower)
    {
        a -= ('a' - 'A');
        return a < b;
    }
    else
    {
        b -= ('a' - 'A');
        return a <= b;
    }
}

int main()
{
    int cases; scanf("%d", &cases);
    while (cases--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), compare);
        do
        {
            cout << s << endl;
        }
        while (next_permutation(s.begin(), s.end(), compare));
    }
    return 0;
}