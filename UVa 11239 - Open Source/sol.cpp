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
map<string, string> Pro;
map<string, string>::iterator pit;
map<string, int> Cnt;
map<string, int>::iterator cit;
map<string, bool> Del;
map<string, bool>::iterator dit;
vector<string> Vec;
bool comp(string A, string B)
{
    if (Cnt[A] != Cnt[B])
        return Cnt[A] > Cnt[B];
    return A < B;
}
int main()
{
    bool test = true;
    while (true)
    {
        string A = "", B = "";
        Pro.clear(); Cnt.clear(); Del.clear(); Vec.clear();
        while (true)
        {
            string str;
            getline(cin, str);
            if (str == "0")
            {
                test = false;
                break;
            }
            if (str == "1")
            {
                break;
            }
            if (isupper(str[0]))
            {
                A = str;
                Cnt[A] = 0;
            }
            else
            {
                B = str;
                pit = Pro.find(B);
                dit = Del.find(B);
                if (pit == Pro.end() && dit == Del.end())
                    Pro[B] = A;
                if (pit != Pro.end() && (*pit).second != A)
                {
                    Del[(*pit).first] = true;
                    Pro.erase(pit);
                }
            }
        }
        if (!test)
            break;
        for (pit = Pro.begin(); pit != Pro.end(); pit++)
            ++Cnt[(*pit).second];
        for (cit = Cnt.begin(); cit != Cnt.end(); cit++)
            Vec.push_back((*cit).first);
        sort(Vec.begin(), Vec.end(), comp);
        int i, j;
        FOI(i, 0, Vec.size() - 1)
        cout << Vec[i] << " " << Cnt[Vec[i]] << endl;
    }
    return 0;
}
