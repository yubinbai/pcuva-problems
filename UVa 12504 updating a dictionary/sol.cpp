#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string in1, in2;
        cin >> in1 >> in2;
        string f1(in1.begin() + 1, in1.end() - 1), f2(in2.begin() + 1, in2.end() - 1);
        map<string, string> m1, m2;
        istringstream iss1(f1), iss2(f2);
        string token;
        while (getline(iss1, token, ','))
        {
            istringstream aux(token);
            string key, val;
            getline(aux, key, ':');
            getline(aux, val, ':');
            m1[key] = val;
        }
        while (getline(iss2, token, ','))
        {
            istringstream aux(token);
            string key, val;
            getline(aux, key, ':');
            getline(aux, val, ':');
            m2[key] = val;
        }
        bool change = false;
        vector<string> del, ins, chg;
        for (map<string, string>::iterator i = m1.begin(); i != m1.end(); ++i)
        {
            if (m2.find((*i).first) == m2.end())
            {
                del.push_back((*i).first);
                change = true;
            }
            else
            {
                if (m2[(*i).first] != (*i).second)
                {
                    chg.push_back((*i).first);
                    change = true;
                }
            }
        }
        for (map<string, string>::iterator i = m2.begin(); i != m2.end(); ++i)
        {
            if (m1.find((*i).first) == m1.end())
            {
                ins.push_back((*i).first);
                change = true;
            }
        }
        if (!change) cout << "No changes" << endl;
        else
        {
            sort(ins.begin(), ins.end());
            sort(del.begin(), del.end());
            sort(chg.begin(), chg.end());
            if (!ins.empty())
            {
                cout << "+";
                for (vector<string>::iterator i = ins.begin(); i != ins.end(); ++i)
                {
                    if (i != ins.begin()) cout << ",";
                    cout << *i;
                }
                cout << endl;
            }
            if (!del.empty())
            {
                cout << "-";
                for (vector<string>::iterator i = del.begin(); i != del.end(); ++i)
                {
                    if (i != del.begin()) cout << ",";
                    cout << *i;
                }
                cout << endl;
            }
            if (!chg.empty())
            {
                cout << "*";
                for (vector<string>::iterator i = chg.begin(); i != chg.end(); ++i)
                {
                    if (i != chg.begin()) cout << ",";
                    cout << *i;
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}