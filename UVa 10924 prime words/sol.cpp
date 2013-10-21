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
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; i++)
        if (N % i == 0)
            return false;
    return true;
}
int main()
{
    bool prime[1100];
    int i;
    string str;
    memset(prime, false, sizeof(prime));
    prime[1] = true;
    prime[2] = true;
    for (i = 3; i < 1100; i++)
        prime[i] = isPrime(i);
    while (cin >> str)
    {
        int len = str.length(), tot = 0;
        for (i = 0; i < len; i++)
        {
            if (islower(str[i]))
                tot += str[i] - 'a' + 1;
            else
                tot += str[i] - 'A' + 27;
        }
        if (prime[tot])
            cout << "It is a prime word.\n";
        else
            cout << "It is not a prime word.\n";
    }
    return 0;
}