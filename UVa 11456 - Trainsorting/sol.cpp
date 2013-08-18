#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int LIS[2005], LDS[2005];

vector<int> sequence;

int lds(int i)
{
    if (LDS[i] != -1) return LDS[i];

    int local_max = 0;
    for (size_t j = i; j < sequence.size(); ++j)
        if (sequence[j] > sequence[i]) local_max = max(local_max, lds(j));

    return LDS[i] = local_max + 1;
}

int lis(int i)
{
    if (LIS[i] != -1) return LIS[i];

    int local_max = 0;
    for (size_t j = i; j < sequence.size(); ++j)
        if (sequence[j] < sequence[i]) local_max = max(local_max, lis(j));

    return LIS[i] = local_max + 1;
}

int main()
{
    int test_cases;
    cin >> test_cases;

    for (size_t i = 0; i < test_cases; ++i)
    {
        int lines; cin >> lines;

        sequence.clear();

        int tmp;
        for (size_t j = 0; j < lines; ++j)
        {
            cin >> tmp; sequence.push_back(tmp);
        }

        // reset DP tables
        memset(LIS, -1, sizeof LIS);
        memset(LDS, -1, sizeof LDS);
        LIS[sequence.size()] = 1;
        LDS[sequence.size()] = 1;

        int local_max = 0;
        for (size_t j = 0; j < sequence.size(); ++j)
            local_max = max(local_max, lis(j) + lds(j) - 1);

        cout << local_max << endl;
    }

    return 0;
}
