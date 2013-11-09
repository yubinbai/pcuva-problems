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
class Elephant
{
public:
    int ID;
    int weight;
    int IQ;
    Elephant(int id, int w, int iq)
    {
        this->ID = id;
        this->weight = w;
        this->IQ = iq;
    }
    static bool cmp(const Elephant &A, const Elephant &B)
    {
        if (A.weight < B.weight)
            return true;
        if (A.weight == B.weight && A.IQ > B.IQ)
            return true;
        return false;
    }
};
vector<int> LongestIncreasingSubsequence(vector<Elephant> v)
{
    int N = v.size();
    vector<int> dp;
    vector<int> last;
    for (int i = 0; i < N; i++)
    {
        dp.push_back(1);
        last.push_back(i);
    }
    int mmax = 0;
    int index = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (v[j].weight < v[i].weight && v[j].IQ > v[i].IQ)
            {
                if (dp[i] <= dp[j])
                {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                    if (dp[i] > mmax)
                    {
                        mmax = dp[i];
                        index = i;
                    }
                }
            }
        }
    }
    vector<int> ret;
    ret.push_back(v[index].ID);
    do
    {
        index = last[index];
        ret.push_back(v[index].ID);
    }
    while (index != last[index]);
    reverse(ret.begin(), ret.end());
    return ret;
}
void print(vector<int> v)
{
    int N = v.size();
    cout << N << endl;
    for (int i = 0; i < N; i++)
        cout << v[i] << endl;
}
int main(int argc, char *argv[])
{
    vector<Elephant> v;
    int count = 0;
    int w, iq;
    while (cin >> w >> iq)
    {
        v.push_back(Elephant(++count, w, iq));
    }
    sort(v.begin(), v.end(), Elephant::cmp);
    print(LongestIncreasingSubsequence(v));
    return 0;
}