#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const char VOWEL[] = "AUEOI";
const char CONSONANT[] = "JSBKTCLDMVNWFXGPYHQZR";

int n;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        // Input.
        cin >> n;
        // Solve.
        string vowel, consonant;
        for (int i = 1, idx = 0; i <= (n + 1) / 2; i++)
        {
            vowel += VOWEL[idx];
            if (i % 21 == 0) idx++;
        }
        for (int i = 1, idx = 0; i <= n / 2; i++)
        {
            consonant += CONSONANT[idx];
            if (i % 5 == 0) idx++;
        }
        sort(vowel.begin(), vowel.end());
        sort(consonant.begin(), consonant.end());
        // Output.
        cout << "Case " << t << ": ";
        for (int i = 1; i <= n; i++)
            cout << (i % 2 ? vowel[i / 2] : consonant[i / 2 - 1]);
        cout << endl;
    }

    return 0;
}
