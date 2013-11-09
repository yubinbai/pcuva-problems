#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
struct Block
{
    int longBase;
    int shortBase;
    int height;
    Block(int a = 0, int b = 0, int c = 0)
    {
        longBase = a;
        shortBase = b;
        height = c;
    }
    friend bool operator < (Block b1, Block b2)
    {
        return b1.longBase < b2.longBase;
    }
    friend bool operator > (Block b1, Block b2)
    {
        return (b1.longBase > b2.longBase) && (b1.shortBase > b2.shortBase);
    }
};
class BabylonTower
{
private:
    priority_queue<Block> sequence;
    int maxHeight;
public:
    void initial();
    void readCase(int);
    void computing();
    void outResult(int);
};
void BabylonTower::initial()
{
    while (!sequence.empty())
    {
        sequence.pop();
    }
    maxHeight = 0;
}
void BabylonTower::readCase(int n)
{
    int x, y, z;
    while (n--)
    {
        cin >> x >> y >> z;
        sequence.push(Block(max(x, y), min(x, y), z));
        sequence.push(Block(max(y, z), min(y, z), x));
        sequence.push(Block(max(z, x), min(z, x), y));
    }
}
void BabylonTower::computing()
{
    queue<Block> q;
    Block b, cur;
    int qsize, mHeight;
    q.push(Block(INT_MAX, INT_MAX, 0));
    while (!sequence.empty())
    {

        b = sequence.top();
        sequence.pop();
        qsize = q.size();
        mHeight = b.height;
        while (qsize--)
        {
            cur = q.front();
            q.pop();
            q.push(cur);
            if (cur > b)
            {
                mHeight = max(mHeight, cur.height + b.height);
            }
        }
        b.height = mHeight;
        q.push(b);
    }
    while (!q.empty())
    {
        maxHeight = max(maxHeight, q.front().height);
        q.pop();
    }
}
void BabylonTower::outResult(int c)
{
    cout << "Case " << c << ": maximum height = " << maxHeight << endl;
}

int main()
{
    BabylonTower bt;
    int n, c = 1;
    while ((cin >> n) && n)
    {
        bt.initial();
        bt.readCase(n);
        bt.computing();
        bt.outResult(c++);
    }
    return 0;
}

