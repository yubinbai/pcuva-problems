#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define SIZE 9
class Piece
{
public:
    int x;
    int y;
    char key;
    Piece(int x, int y, char key) : x(x), y(y), key(key) {};
};
bool rook(char board[SIZE][SIZE], Piece *p, Piece *king)
{
    int i, j;
    if (king->y == p->y)
    {
        i = p->x - 1;
        j = p->y;
        while (i > 0 && board[i][j] == '.' && i > king->x) i--;
        if (king->x == i) return true;
        i = p->x + 1;
        while (i < 8 && board[i][j] == '.' && i < king->x) i++;
        if (king->x == i) return true;
    }
    if (king->x == p->x)
    {
        i = p->x;
        j = p->y - 1;
        while (j > 0 && board[i][j] == '.' && j > king->y) j--;
        if (king->y == j) return true;
        j = p->y + 1;
        while (j < 8 && board[i][j] == '.' && j < king->y) j++;
        if (king->y == j) return true;
    }
    return false;
}
bool bishop(char board[SIZE][SIZE], Piece *p, Piece *king)
{
    int i, j;
    i = p->x - 1;
    j = p->y - 1;
    while (i >= 0 && j >= 0)
    {
        if (i == king->x && j == king->y) return true;
        if (board[i][j] != '.') break;
        i--; j--;
    }
    i = p->x + 1;
    j = p->y + 1;
    while (i < 8 && j < 8)
    {
        if (i == king->x && j == king->y) return true;
        if (board[i][j] != '.') break;
        i++; j++;
    }
    i = p->x - 1;
    j = p->y + 1;
    while (i >= 0 && j < 8)
    {
        if (i == king->x && j == king->y) return true;
        if (board[i][j] != '.') break;
        i--; j++;
    }
    i = p->x + 1;
    j = p->y - 1;
    while (i < 8 && j >= 0)
    {
        if (i == king->x && j == king->y) return true;
        if (board[i][j] != '.') break;
        i++; j--;
    }
    return false;
}
bool queen(char board[SIZE][SIZE], Piece *p, Piece *king)
{
    return rook(board, p, king) || bishop(board, p, king);
}
bool knight(char board[SIZE][SIZE], Piece *p, Piece *king)
{
    if (p->x - 2 == king->x && p->y - 1 == king->y) return true;
    if (p->x - 2 == king->x && p->y + 1 == king->y) return true;
    if (p->x + 2 == king->x && p->y - 1 == king->y) return true;
    if (p->x + 2 == king->x && p->y + 1 == king->y) return true;
    if (p->x - 1 == king->x && p->y - 2 == king->y) return true;
    if (p->x - 1 == king->x && p->y + 2 == king->y) return true;
    if (p->x + 1 == king->x && p->y - 2 == king->y) return true;
    if (p->x + 1 == king->x && p->y + 2 == king->y) return true;
    return false;
}
bool check_whites(char board[SIZE][SIZE], queue<Piece *> &whites, Piece *b_king)
{
    while (!whites.empty())
    {
        Piece *p = whites.front();
        whites.pop();
        switch (p->key)
        {
        case 'P':
            if (b_king->x == p->x - 1 && (b_king->y == p->y - 1 || b_king->y == p->y + 1))
            {
                return true;
            }
            break;
        case 'R':
            if (rook(board, p, b_king)) return true;
            break;
        case 'B':
            if (bishop(board, p, b_king)) return true;
            break;
        case 'Q':
            if (queen(board, p, b_king)) return true;
            break;
        case 'N':
            if (knight(board, p, b_king)) return true;
            break;
        default:
            break;
        }
        delete p;
    }
    return false;
}
bool check_blacks(char board[SIZE][SIZE], queue<Piece *> &blacks, Piece *w_king)
{
    while (!blacks.empty())
    {
        Piece *p = blacks.front();
        blacks.pop();
        switch (p->key)
        {
        case 'p':
            if (w_king->x == p->x + 1 && (w_king->y == p->y - 1 || w_king->y == p->y + 1))
            {
                return true;
            }
            break;
        case 'r':
            if (rook(board, p, w_king)) return true;
            break;
        case 'b':
            if (bishop(board, p, w_king)) return true;
            break;
        case 'q':
            if (queen(board, p, w_king)) return true;
            break;
        case 'n':
            if (knight(board, p, w_king)) return true;
            break;
        default:
            break;
        }
        delete p;
    }
    return false;
}
int main()
{
    char board[SIZE][SIZE];
    int game = 1;
    while (true)
    {
        Piece *b_king = NULL;
        Piece *w_king = NULL;
        queue<Piece *> whites;
        queue<Piece *> blacks;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> board[i][j];
                if (board[i][j] != '.')
                {
                    Piece *tmp =
                        new Piece(i, j, board[i][j]);
                    //if is upper case
                    if (board[i][j] < 'a')
                    {
                        whites.push(tmp);
                    }
                    else
                    {
                        blacks.push(tmp);
                    }
                    if (board[i][j] == 'k')
                    {
                        b_king = new Piece(i, j, 'k');
                    }
                    else if (board[i][j] == 'K')
                    {
                        w_king = new Piece(i, j, 'K');
                    }
                }
            }
        }
        if (b_king == NULL && w_king == NULL) break;
        cout << "Game #" << game++ << ": ";
        if (check_blacks(board, blacks, w_king))
        {
            cout << "white king is in check." << endl;
        }
        else if (check_whites(board, whites, b_king))
        {
            cout << "black king is in check." << endl;
        }
        else
        {
            cout << "no king is in check." << endl;
        }
        delete b_king;
        delete w_king;
    }
    return 0;
}
