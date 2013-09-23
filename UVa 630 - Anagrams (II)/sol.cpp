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
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int i, j;
        map<string, string> Map;
        vector< string > Word(N);
        FOI(i, 0, N - 1)
        {
            cin >> Word[i];
            string temp = Word[i];
            sort(temp.begin(), temp.end());
            Map[Word[i]] = temp;
        }
        while (true)
        {
            string str, temp;
            cin >> str;
            if (str == "END")
                break;
            temp = str;
            sort(temp.begin(), temp.end());
            vector< string > vec;
            cout << "Anagrams for: " << str << endl;
            FOI(i, 0, N - 1)
            {
                if (Map[Word[i]] == temp)
                    vec.push_back(Word[i]);
            }
            int SZ = vec.size();
            if (SZ == 0)
                cout << "No anagrams for: " << str << endl;
            else
                FOI(i, 0, SZ - 1)
                printf("%3d) %s\n", i + 1, vec[i].c_str());
        }
        if (T)
            cout << endl;
    }
    return 0;
}
