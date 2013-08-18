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

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int N, zero, ones;
        cin >> N >> ones;
        int arr[N], i;
        for (i = 0; i < N - ones; i++)
            arr[i] = 0;
        for (i = N - ones; i < N; i++)
            arr[i] = 1;
        do
        {
            for (i = 0; i < N; i++)
                cout << arr[i];
            cout << endl;
        }
        while (next_permutation(arr, arr + N));

        if (test > 0)
            cout << endl;
    }
    return 0;
}