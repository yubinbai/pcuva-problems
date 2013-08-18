#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Team
{

public:

    int points;
    int games;
    int wins;
    int ties;
    int losses;
    int scored;
    int against;
    string name;
    string nameM;

    Team()
    {
        points = 0;
        games = 0;
        wins = 0;
        ties = 0;
        losses = 0;
        scored = 0;
        against = 0;
    }

    void setname(string n)
    {
        name = n;
        nameM = n;
        transform(nameM.begin(), nameM.end(), nameM.begin(), ::toupper);
    }

    void add(int s, int a)
    {
        games++;
        scored += s;
        against += a;
        if (s > a)
        {
            wins++;
            points += 3;
        }
        else if (s == a)
        {
            ties++;
            points += 1;
        }
        else
        {
            losses++;
        }
    }

};

bool ordenar(const Team &uno, const Team &otro)
{
    if (uno.points > otro.points) return true;
    else if (uno.points < otro.points) return false;
    if (uno.wins > otro.wins) return true;
    else if (uno.wins < otro.wins) return false;
    if (uno.scored - uno.against > otro.scored - otro.against) return true;
    else if (uno.scored - uno.against < otro.scored - otro.against) return false;
    if (uno.scored > otro.scored) return true;
    else if (uno.scored < otro.scored) return false;
    if (uno.games < otro.games) return true;
    else if (uno.games > otro.games) return false;
    return uno.nameM < otro.nameM;
}

int main()
{
    int T;
    cin >> T;
    cin.get();
    for (int t = 0; t < T; ++t)
    {
        string torneo;
        getline(cin, torneo);
        if (t > 0) cout << endl;
        cout << torneo << endl;
        int E;
        cin >> E;
        cin.get();
        map<string, Team> m;
        for (int e = 0; e < E; ++e)
        {
            string eq;
            getline(cin, eq);
            m[eq] = Team();
            m[eq].setname(eq);
        }
        int J;
        cin >> J;
        cin.get();
        for (int j = 0; j < J; ++j)
        {
            string juego;
            getline(cin, juego);
            int p1 = juego.find('#');
            int p2 = juego.find('@');
            int p3 = juego.find('#', p1 + 1);
            string eq1 = juego.substr(0, p1);
            int g1 = atoi((juego.substr(p1 + 1, p2 - p1 - 1)).data());
            int g2 = atoi(juego.substr(p2 + 1, p3 - p2 - 1).data());
            string eq2 = juego.substr(p3 + 1, juego.size() - 1 - p3);
            m[eq1].add(g1, g2);
            m[eq2].add(g2, g1);
        }
        vector<Team> v;
        for (map<string, Team>::iterator it = m.begin(); it != m.end(); ++it) v.push_back((*it).second);
        sort(v.begin(), v.end(), ordenar);
        for (int i = 0; i < v.size(); ++i)
            cout << i + 1 << ") " << v[i].name << " " << v[i].points << "p, " << v[i].games << "g (" << v[i].wins << "-" << v[i].ties << "-" << v[i].losses << "), " << v[i].scored - v[i].against << "gd (" << v[i].scored << "-" << v[i].against << ")" << endl;
    }
}

