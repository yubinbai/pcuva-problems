#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool p[100001]; //criba erastotenes

int main()
{
    memset(p, true, sizeof(bool) * 100001);
    p[0] = false;
    p[1] = false;
    for (int i = 2; i < 100001; ++i)
    {
        if (p[i])
        {
            for (int j = i + i; j < 100001; j += i) p[j] = false;
        }
    }
    string s;
    cin >> s;
    while (s != "0")
    {
        for (int i = (s.size() < 5 ? s.size() : 5); i > 0; --i)
        {
            int maxprime = -1;
            for (int j = 0; j <= s.size() - i; ++j)
            {
                string sub = s.substr(j, i);
                istringstream iss(sub);
                int k;
                iss >> k;
                if (p[k] && k > maxprime) maxprime = k;
            }
            if (maxprime != -1)
            {
                cout << maxprime << endl;
                break;
            }
        }
        cin >> s;
    }
}
