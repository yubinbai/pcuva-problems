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
        int N, i, j;
        cin >> N;
        string phone[N];
        bool stat = true;
        size_t found;
        for (i = 0; i < N; i++)
        {
            string temp;
            cin >> phone[i];
        }
        sort(phone, phone + N);
        for (i = 0; i < N; i++)
        {
            for (j = i + 1; j < N; j++)
            {
                if (phone[i].length() >= phone[j].length())
                    continue;
                found = phone[j].find(phone[i]);
                if (found == 0)
                {
                    stat = false;
                    break;
                }
            }
            if (!stat)
                break;
        }
        if (stat)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}