/*

179487 * 4 = 717948（10 ）

4*7=28     28!=7    28/10=2    28=8
4*8+2=34    34!=7    37/10=3    34=4
4*4+3=19    19!=7    19/10=1    19=9
4*9+1=37    37!=7    37/10=3    37=7
4*7+3=31    31!=7    31/10=3    31=1
4*1+3=7      7==7 (then end)

*/

#include <iostream>
#include <cmath>
#include <map>

using namespace std;

char NUMS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Characters that may be used
map<char, int> mNUMS;

int convB(string n, int base);

int main()
{
    for (int i = 0; i <= 36; ++i) mNUMS[NUMS[i]] = i;
    int b, l, m;
    string ls, ms;
    while (cin >> b >> ls >> ms)
    {
        l = (ls.size() == 1) ? mNUMS[ls[0]] : convB(ls, 10);
        m = (ms.size() == 1) ? mNUMS[ms[0]] : convB(ms, 10);
        int c = 0, n = l, k = 0;;
        while (true)
        {
            ++k;
            n = (m * n + c);
            if (n == l) break;
            c = n / b;
            n = n % b;
        }
        cout << k << endl;
    }
}

int convB(string n, int base)
{
    int d = 0;
    for (string::iterator it = n.end() - 1; it >= n.begin(); --it)
    {
        d += pow(base, (n.end() - 1) - it) * mNUMS[*it];
    }
    return d;
}
