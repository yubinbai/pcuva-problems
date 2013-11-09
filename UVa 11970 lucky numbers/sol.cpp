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
typedef pair<int, int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<vi>     vvi;
typedef vector<vii>    vvii;
typedef map<int, int>    mii;
int main()
{
    int TC;
    cin >> TC;
    int N, CC = 1;
    while (TC--)
    {
        int isq;
        cin >> N;
        printf("Case %d:", CC++);
        stack<int> os;
        for (int i = 1; (isq = i * i) < N; i++)
        {
            if ( (N - isq) % i == 0)
            {
                os.push(N - isq);
            }
        }
        while (!os.empty())
        {
            printf(" %d", os.top());
            os.pop();
        }
        putchar('\n');
    }
    return 0;
}