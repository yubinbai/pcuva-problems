#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        cout << "------------------------------------------------------------" << endl;
        vector<string> v(N);
        int max = -1;
        for (int i = 0; i < N; ++i)
        {
            cin >> v[i];
            if (int(v[i].size()) > max) max = v[i].size();
        }
        max += 2;
        int cols = 60 / max;
        if (cols == 0) cols = 1;
        int fils = N / cols + (N & 1 == 1 ? 1 : 0);
        if (cols == 1) fils = N;
        sort(v.begin(), v.end());
        for (int f = 0; f < fils; ++f)
        {
            for (int c = 0; c < cols; ++c)
            {
                int i = c * fils + f;
                if (i < v.size())
                    cout << v[i] << string(max - int(v[i].size()), ' ');
            }
            cout << endl;
        }
    }
}