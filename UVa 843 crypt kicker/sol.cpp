#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;
bool finished = false;
bool parse2word(string line, vector < string > &word)
{
    istringstream iss(line);
    string w;
    bool found;
    while (iss >> w)
    {
        found = false;
        for (int i = 0; i < word.size(); i++)
            if (w == word[i])
                found = true;
        if (!found)
            word.push_back(w);
    }
    return word.size() > 0;
}
bool cmp(char a, char b)
{
    return a < b;
}
bool conflicts(string cipher)
{
    sort(&cipher[0], &cipher[0] + cipher.length(), cmp);
    for (int i = 0; i < cipher.length() - 1; i++)
        if (cipher[i] != '*' && cipher[i + 1] != '*' &&
                cipher[i] == cipher[i + 1])
            return true;
    return false;
}
bool match(string d, string w, string &cipher)
{
    string tmp = cipher;
    if (d.length() != w.length())
        return false;
    for (int i = 0; i < w.length(); i++)
    {
        if (cipher[w[i] - 'a'] == '*')
            cipher[w[i] - 'a'] = d[i];
        else
        {
            if (cipher[w[i] - 'a'] != d[i])
            {
                cipher = tmp;
                return false;
            }
        }
    }
    if (conflicts(cipher))
    {
        cipher = tmp;
        return false;
    }
    return true;
}
void output(string line, string cipher)
{
    for (int i = 0; i < line.length(); i++)
        if (line[i] == ' ')
            cout << ' ';
        else
            cout << cipher[line[i] - 'a'];
    cout << endl;
}
void decipher(vector < string > &dict, vector < string > &word, int start,
              string &cipher)
{
    string tmp = cipher;
    if (start == word.size())
    {
        finished = !conflicts(cipher);
        return;
    }
    for (int i = 0; i < dict.size(); i++)
        if (match(dict[i], word[start], cipher))
        {
            decipher(dict, word, start + 1, cipher);
            if (finished)
                return;
            else
                cipher = tmp;
        }
}
int main(int argc, char *argv[])
{
    string line;
    int count;
    vector < string > dict;
    map < string, int > exist;
    map < string, int >::iterator it;
    vector < string > word;
    cin >> count;
    cin.ignore();
    for (int i = 0; i < count; i++)
    {
        getline(cin, line);
        it = exist.find(line);
        if (it == exist.end())
        {
            dict.push_back(line);
            exist.insert(make_pair< string, int >(line, dict.size() - 1));
        }
    }
    while (getline(cin, line))
    {
        if (line.length() == 0)
        {
            cout << endl;
            continue;
        }
        word.clear();
        parse2word(line, word);
        finished = false;
        string cipher(26, '*');
        if (!(word.size() > dict.size()))
            decipher(dict, word, 0, cipher);
        output(line, cipher);
    }
    return 0;
}
