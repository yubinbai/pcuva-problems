#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::pop_heap;
using std::push_heap;
#define ID_NIL 0
#define HASH_TABLE_BUCKET_SIZE (1 << 12)
class Direction
{
public:
    int dRow;
    int dCol;
    Direction(int r = 0, int c = 0): dRow(r), dCol(c) {}
};
vector <Direction> dir(4);
vector <char> opChar(4);
enum Operation
{
    up = 0, down, left, right, nil
};
class Initializer
{
public:
    Initializer()
    {
        dir[down] = Direction(1, 0);
        dir[right] = Direction(0, 1);
        dir[up] = Direction(-1, 0);
        dir[left] = Direction(0, -1);
        opChar[down] = 'd';
        opChar[right] = 'r';
        opChar[up] = 'u';
        opChar[left] = 'l';
    }
};
Initializer init;
class State
{
public:
    /* ***************************************************
     x xxxx xxx xxx xxx xxx xxx xxx xxx xxx xxx
     u xPos  9   8   7   6   5   4   3   2   1
     The storage of a 32 bit integer for parId and id,
     where u means unused, xPos means the position of x,
     i means the ith tile's number.
    *************************************************** */
    int parId;
    int id;
    Operation oper;
    int f, g;
    State(): parId(ID_NIL), id(010012345670/*oct*/),
        oper(nil), f(0), g(0) {}
    void SetF()
    {
        int xPos = id >> 27;
        int h = 0;
        for (int i = 0; i < 9; ++i)
        {
            if (i == xPos)
                continue;
            int tile = (07 & (id >> (i * 3)));
            int r = tile / 3;
            int c = tile % 3;
            int oR = i / 3;
            int oC = i % 3;
            h += abs(r - oR) + abs(c - oC);
        }
        f = g + h;
    }
    void GetMat()
    {
        int xPos;
        id = 0;
        int n = 0;
        while (n < 9)
        {
            char c = cin.get();
            if (! cin)
                exit(0);
            if (c == 'x')
            {
                xPos = n;
                ++n;
            }
            else if ('1' <= c && c <= '8')
            {
                id |= ((c - '0' - 1) << n * 3);
                ++n;
            }
        }
        id |= (xPos << 27);
        g = 0;
        parId = ID_NIL;
        oper = nil;
        SetF();
    }
    State Move(Operation op)
    {
        int oldXPos = id >> 27;
        int newRow = oldXPos / 3 + dir[op].dRow;
        int newCol = oldXPos % 3 + dir[op].dCol;
        if (! (0 <= newRow && newRow < 3 &&
                0 <= newCol && newCol < 3))
            return *this;
        State ret = *this;
        int newXPos = newRow * 3 + newCol;
        // tile to be moved
        int tile = (id >> (newXPos * 3)) & 07;
        // set the moved tile to its new position
        ret.id |= (tile << (oldXPos * 3));
        // set the new position of x to be 0
        ret.id &= (~(07 << (newXPos * 3)));
        // reset xPos
        ret.id &= (~(0xf << 27));
        ret.id |= (newXPos << 27);
        ret.g = g + 1;
        ret.parId = id;
        ret.SetF();
        ret.oper = op;
        return ret;
    }
    bool IsSolvable() const
    {
        // in reverse order number
        int rev = 0;
        int xPos = id >> 27;
        for (int i = 0; i < 9; ++i)
        {
            if (i == xPos)
                continue;
            int tile = (id >> (i * 3)) & 07;
            for (int k = 0; k < i; ++k)
            {
                if (k == xPos)
                    continue;
                int tileK = (id >> (k * 3)) & 07;
                if (tileK > tile)
                    ++rev;
            }
        }
        return rev % 2 == 0;
    }
    bool IsTargetState() const
    {
        // 010076543210 is target state's id
        return id == 010076543210;
    }
};
class StateFCmp
{
public:
    bool operator()(const State &lhs, const State &rhs)
    {
        return lhs.f > rhs.f;
    }
};
class HashTable
{
public:
    vector <vector <State> > bucket;
    HashTable(): bucket(HASH_TABLE_BUCKET_SIZE) {}
    // not tested, I think the hash function is ok.
    int IDHash(int id)
    {
        return (((id * id) >> 2) ^ ((id * id) >> 1) ^ (id * id))
               & (HASH_TABLE_BUCKET_SIZE - 1);
    }
    State FindByID(int id)
    {
        int h = IDHash(id);
        for (size_t i = 0; i < bucket[h].size(); ++i)
        {
            if (bucket[h][i].id == id)
                return bucket[h][i];
        }
        return State();
    }
    bool IsInTable(const State &st)
    {
        return FindByID(st.id).id == st.id;
    }
    void Insert(const State &st)
    {
        if (IsInTable(st))
            return;
        int h = IDHash(st.id);
        bucket[h].push_back(st);
    }
};
void PrintPath(const State &st, HashTable &opened)
{
    if (st.parId == ID_NIL)
        return;
    // Print st's parent before print st
    PrintPath(opened.FindByID(st.parId), opened);
    cout << opChar[st.oper];
}
void AStar(const State &startState)
{
    if (! startState.IsSolvable())
    {
        cout << "unsolvable\n";
        return;
    }
    if (startState.IsTargetState())
    {
        cout << "\n";
        return;
    }
    vector <State> open;
    HashTable opened;
    open.push_back(startState);
    push_heap(open.begin(), open.end(), StateFCmp());
    opened.Insert(startState);
    while (! open.empty())
    {
        // Pop a state with minimum f
        pop_heap(open.begin(), open.end(), StateFCmp());
        State curSt = open.back();
        open.pop_back();
        // Expand the popped state
        for (size_t i = 0; i < dir.size(); ++i)
        {
            State nextSt = curSt.Move(Operation(i));
            if (opened.IsInTable(nextSt))
                continue;
            open.push_back(nextSt);
            push_heap(open.begin(), open.end(), StateFCmp());
            opened.Insert(nextSt);
            if (nextSt.IsTargetState())
            {
                PrintPath(nextSt, opened);
                cout << "\n";
                return;
            }
        }// End for
    }// End while
    cout << "unsolvable\n";
}
int main()
{
    int cs;
    cin >> cs;
    for (int c = 0; c < cs; ++c)
    {
        State st;
        st.GetMat();
        if (c != 0)
            cout << "\n";
        AStar(st);
    }
    return 0;
}
