#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

map<char, int> Map;
map<char, int>::iterator it;

bool comp(char A, char B)
{
    if (Map[A] != Map[B])
        return Map[A] > Map[B];
    return A < B;
}

int main()
{
    string alfa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector< char > Char;
    int i, j, N;
    FOI(i, 0, 25) Map[alfa[i]] = 0;
    cin >> N;
    string str;
    getline(cin, str);
    while (N--)
    {
        getline(cin, str);
        int L = str.length() - 1;
        FOI(i, 0, L)
        {
            if (isalpha(str[i]))
            {
                char C = toupper(str[i]);
                if (Map[C] == 0) Char.push_back(C);
                ++Map[C];
            }
        }
    }
    sort(Char.begin(), Char.end(), comp);
    int S = Char.size() - 1;
    FOI(i, 0, S)
    cout << Char[i] << " " << Map[Char[i]] << endl;
    return 0;
}