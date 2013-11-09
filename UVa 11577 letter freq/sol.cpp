#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
namespace solution
{
typedef std::istringstream ISS;
typedef std::ostringstream OSS;
typedef std::vector<std::string> VS;
typedef long long LL;
typedef int INT;
typedef std::vector<INT> VI;
typedef std::vector<VI> VVI;
typedef std::pair<INT, INT> II;
typedef std::vector<II> VII;
}
namespace solution
{
class ISolution
{
public:
    virtual void init() {};
    virtual bool input()
    {
        return false;
    };
    virtual void output() {};
    virtual int run() = 0;
};
}
namespace solution
{
using namespace std;
string s;
int get_number()
{
    string s;
    getline(cin, s);
    ISS iss(s);
    int res;
    iss >> res;
    return res;
}
string solve()
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int cnt[26];
    for ( char c = 'a'; c <= 'z'; ++ c )
    {
        int i = c - 'a';
        cnt[i] = count(s.begin(), s.end(), c);
    }
    int max_cnt = *max_element(cnt, cnt + 26);
    string res = "";
    for ( char c = 'a'; c <= 'z'; ++ c )
        if ( cnt[c - 'a'] == max_cnt )
            res += c;
    return res;
}
class Solution: public ISolution
{
public:
    bool input()
    {
        return getline(cin, s);
    }
    void output( string result )
    {
        cout << result << endl;
    }
    int run()
    {
        int tests = get_number();
        for ( int i = 0; i < tests; ++ i )
        {
            init();
            input();
            output(solve());
        }
        return 0;
    }
};
}
int main()
{
    return solution::Solution().run();
}
