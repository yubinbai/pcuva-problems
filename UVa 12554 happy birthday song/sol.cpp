#include <iostream>

using namespace std;

int main()
{
    string song[] = {"Happy", "birthday", "to", "you",
                     "Happy", "birthday", "to", "you",
                     "Happy", "birthday", "to", "Rujia",
                     "Happy", "birthday", "to", "you"
                    };
    string p[100];
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i) cin >> p[i];
        int i = 0, j = 0;
        for (; i < n; ++i, j = (j + 1) % 16) cout << p[i] << ": " << song[j] << endl; //all sing
        i = 0;
        while (j != 0)
        {
            cout << p[i] << ": " << song[j] << endl; //all sing
            i = (i + 1) % n;
            j = (j + 1) % 16;
        };
    }
}