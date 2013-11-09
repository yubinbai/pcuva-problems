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
int toBinary(vector<int> Vec)
{
    int i, cnt = 0;
    FOI(i, 0, Vec.size() - 1)
    cnt += (Vec[i] << i);
    return cnt;
}
int main()
{
    while ( true )
    {
        int N;
        int i, j;
        cin >> N;
        if ( N == 0 )
            break;
        vector<int> bit, bin, A(32, 0), B(32, 0);
        while ( N > 0 )
        {
            int rem = N % 2;
            bin.push_back(rem);
            N /= 2;
        }
        for (i = 0; i < bin.size(); i++)
            if (bin[i] == 1)
                bit.push_back(i);
        for (i = 0; i < bit.size(); i ++)
        {
            if ( i % 2 == 0 )
                A[bit[i]] = 1;
            else
                B[bit[i]] = 1;
        }
        cout << toBinary(A) << " " << toBinary(B) << endl;
    }
    return 0;
}