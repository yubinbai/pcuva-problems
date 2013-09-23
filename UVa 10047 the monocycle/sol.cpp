#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct pos
{
    int d;
    int z;
    int i;
    int j;
    pos(int _d, int _z, int _i, int _j)
    {
        d = _d;
        z = _z;
        i = _i;
        j = _j;
    }
};
bool find(char **m, bool ** **memory, int w, int h, vector<pos *> &p, int &c);
int main()
{
    int w, h, cases = 1;
    cin >> h >> w;
    while (!(w == 0 || h == 0))
    {
        bool ** **memory = new bool ***[4];
        for (int d = 0; d < 4; ++d)
        {
            memory[d] = new bool **[5];
            for (int z = 0; z < 5; ++z)
            {
                memory[d][z] = new bool*[h];
                for (int i = 0; i < h; ++i)
                {
                    memory[d][z][i] = new bool[w];
                    for (int j = 0; j < w; ++j) memory[d][z][i][j] = false;
                }
            }
        }
        vector<pos *> p;
        char **m = new char*[h];
        for (int i = 0; i < h; ++i)
        {
            m[i] = new char[w];
            for (int j = 0; j < w; ++j)
            {
                cin >> m[i][j];
                if (m[i][j] == 'S') p.push_back(new pos(0, 0, i, j));
            }
        }
        if (cases > 1) cout << endl;
        cout << "Case #" << cases++ << endl;
        int c = 0;
        if (find(m, memory, w, h, p, c))
        {
            cout << "minimum time = " << c << " sec" << endl;
        }
        else
        {
            cout << "destination not reachable" << endl;
        }
        cin >> h >> w;
    }
}
int d[][2] = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool find(char **m, bool ** **memory, int w, int h, vector<pos *> &p, int &c)
{
    if (p.empty()) return false;
    vector<pos *> np;
    for (vector<pos *>::iterator it = p.begin(); it != p.end(); ++it)
    {
        if (m[(*it)->i][(*it)->j] == 'T' && (*it)->z == 0) return true;

        pos *g1 = new pos((((*it)->d - 1 < 0) ? 3 : (*it)->d - 1), (*it)->z, (*it)->i, (*it)->j);
        if (!memory[g1->d][g1->z][g1->i][g1->j])
        {
            memory[g1->d][g1->z][g1->i][g1->j] = true;
            np.push_back(g1);
        }
        pos *g2 = new pos((((*it)->d + 1 > 3) ? 0 : (*it)->d + 1), (*it)->z, (*it)->i, (*it)->j);
        if (!memory[g2->d][g2->z][g2->i][g2->j])
        {
            memory[g2->d][g2->z][g2->i][g2->j] = true;
            np.push_back(g2);
        }

        int ni = (*it)->i + d[(*it)->d][0];
        int nj = (*it)->j + d[(*it)->d][1];
        if (ni >= 0 && nj >= 0 && ni < h && nj < w && m[ni][nj] != '#')
        {
            pos *mov = new pos((*it)->d, ((*it)->z + 1) % 5, ni, nj);
            if (!memory[mov->d][mov->z][mov->i][mov->j])
            {
                memory[mov->d][mov->z][mov->i][mov->j] = true;
                np.push_back(mov);
            }
        }
    }
    ++c;
    return find(m, memory, w, h, np, c);;
}
