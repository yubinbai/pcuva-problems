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

#define FOI(i, A, B) for(i=A; i<=B; i++)
#define FOD(i, A, B) for(i=A; i>=B; i--)

string SI[] = {"2", "2", "2", "3", "3", "3", "4", "4", "4", "5", "5", "5", "6", "6", "6", "7", "", "7", "7", "8", "8", "8", "9", "9", "9", ""};

string mod(string S)
{
    int i = 0, L = S.length();
    string R = "";
    FOI(i, 0, L - 1)
    {
        if (isdigit(S[i]))
            R += S[i];
        else if (isalpha(S[i]))
            R += SI[S[i] - 'A'];
        else
            continue;
    }
    return R;
}

string con(string S)
{
    S.insert(3, "-");
    return S;
}

int main()
{
    //freopen("testI.txt", "r", stdin);
    //freopen("testO.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int N, i;
        cin >> N;
        map<string, int> Map;
        map<string, int>::iterator it;
        while (N--)
        {
            string str;
            cin >> str;
            str = mod(str);
            it = Map.find(str);
            if (it != Map.end())
                Map[str] += 1;
            else
                Map[str] = 1;
        }
        vector< string > V;
        for (it = Map.begin(); it != Map.end(); it++)
        {
            if ((*it).second > 1)
                V.push_back((*it).first);
        }
        if (V.size() == 0)
            cout << "No duplicates." << endl;
        else
        {
            sort(V.begin(), V.end());
            FOI(i, 0, V.size() - 1)
            cout << con(V[i]) << " " << Map[V[i]] << endl;
        }
        if (T)
            cout << endl;
    }
    return 0;
}
