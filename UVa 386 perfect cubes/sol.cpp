#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int sum, a, b, c, d;
} cube_triple;

bool triple_less(const cube_triple &lhs, const cube_triple &rhs)
{
    return lhs.sum < rhs.sum;
}

int main()
{
    ios::sync_with_stdio(false);

    int cubes[201];
    for (int i(1); i < 201; ++i)
    {
        cubes[i] = i * i * i;
    }

    vector<cube_triple> results;
    for (int a(3); a < 201; ++a)
    {
        for (int i(2); i < 200; ++i)
        {
            for (int j(i); j < 200; ++j)
            {
                for (int k(j); k < 200; ++k)
                {
                    if (cubes[a] < cubes[i] + cubes[j] + cubes[k]) break;
                    if (cubes[a] == cubes[i] + cubes[j] + cubes[k])
                    {
                        //cout << "Cube = " << cubes[a] << ", Triple = (" << cubes[i] << "," << cubes[j] << "," << cubes[k] << ")" << endl;
                        cube_triple stub = {i + j + k, a, i, j, k};
                        results.push_back(stub);
                    }
                }
            }
        }
    }
    for (vector<cube_triple>::const_iterator c(results.begin()), end(results.end()); c != end; ++c)
        cout << "Cube = " << c->a << ", Triple = (" << c->b << "," << c->c << "," << c->d << ")" << endl;
    return 0;
}