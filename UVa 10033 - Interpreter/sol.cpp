#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int RAM_SIZE = 1001;
const int REGS = 11;
int main()
{
    int cases;
    int pc;
    vector<int> ram(RAM_SIZE);
    vector<int> regs(REGS);
    cin >> cases;
    cin.ignore(100, '\n');
    cin.ignore(100, '\n');
    while (cases--)
    {
        int result = 0;
        fill(ram.begin(), ram.end(), 0);
        fill(regs.begin(), regs.end(), 0);
        pc = 0;
        while (cin.peek() != '\n' && !cin.eof())
        {
            int inst;
            cin >> inst;
            cin.ignore(100, '\n');
            ram[pc++] = inst;
        }
        cin.ignore(100, '\n');
        pc = 0;
        while (true)
        {
            int inst = ram[pc];
            result++;
            if (inst == 100) break;
            int c = inst / 100;
            int d = inst % 100 / 10;
            int n = inst % 10;
            switch (c)
            {
            case 2:
                regs[d] = n;
                break;
            case 3:
                regs[d] = (regs[d] + n) % 1000;
                break;
            case 4:
                regs[d] = (regs[d] * n) % 1000;
                break;
            case 5:
                regs[d] = regs[n];
                break;
            case 6:
                regs[d] = (regs[d] + regs[n]) % 1000;
                break;
            case 7:
                regs[d] = (regs[d] * regs[n]) % 1000;
                break;
            case 8:
                regs[d] = ram[regs[n]];
                break;
            case 9:
                ram[regs[n]] = regs[d];
                break;
            case 0:
                if (regs[n] != 0) pc = regs[d] - 1;
                break;
            }
            pc++;
        }
        cout << result << endl;
        if (cases > 0)
        {
            cout << endl;
        }
    }
    return 0;
}
