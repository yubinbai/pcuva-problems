#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int nWords, nRules;
string words[120], rules[1050];
void backtrack(string soFar, int posRule, int rule)
{
    if (posRule == rules[rule].length())
        cout << soFar << endl;
    else
    {
        if (rules[rule][posRule] == '#')
            for (int i = 0; i < nWords; i++)
                backtrack(soFar + words[i], posRule + 1, rule);
        else if (rules[rule][posRule] == '0')
            for (int i = 0; i <= 9; i++)
                backtrack(soFar + (char)(i + 48), posRule + 1, rule);
    }
}
int main()
{
    while (scanf("%d", &nWords) == 1)
    {
        for (int i = 0; i < nWords; i++)
        {
            cin >> words[i];
        }
        scanf("%d", &nRules);
        for (int i = 0; i < nRules; i++)
        {
            cin >> rules[i];
        }
        for (int i = 0; i < nRules; i++)
        {
            printf("--\n");
            backtrack("", 0, i);
        }
    }
    return 0;
}
