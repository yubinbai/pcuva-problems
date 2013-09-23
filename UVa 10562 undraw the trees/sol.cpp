#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int lineCount_max = 200, nr_chrs_max = 200;
string prof_tree[lineCount_max + 1];
void print_tree(int lineCount, int i, int j)
{
    if (i == lineCount)
        cout << "()";
    else
    {
        const string &pt = prof_tree[i];
        if (j >= pt.length())
            cout << "()";
        else if (pt[j] == ' ')
            cout << "()";
        else if (pt[j] == '|')
            print_tree(lineCount, i + 1, j);
        else if (pt[j] == '-')
        {
            while (j && pt[j - 1] == '-')
                j--;
            cout << '(';
            for ( ; pt[j] == '-'; j++)
            {
                if (j < prof_tree[i + 1].length() && prof_tree[i + 1][j] != ' ')
                    print_tree(lineCount, i + 1, j);
            }
            cout << ')';
        }
        else
        {
            cout << pt[j];
            print_tree(lineCount, i + 1, j);
        }
    }
}
int main()
{
    string s;
    getline(cin, s);
    istringstream iss(s);
    int t;
    iss >> t;
    while (t--)
    {
        int lineCount = 0;
        while (true)
        {
            getline(cin, prof_tree[lineCount]);
            if (prof_tree[lineCount][0] == '#')
                break;
            lineCount++;
        }
        cout << '(';
        if (lineCount)
        {
            const string &pt = prof_tree[0];
            for (int j = 0, e = pt.length(); j < e; j++)
                if (pt[j] != ' ')
                {
                    cout << pt[j];
                    print_tree(lineCount, 1, j);
                }
        }
        cout << ")\n";
    }
    return 0;
}
