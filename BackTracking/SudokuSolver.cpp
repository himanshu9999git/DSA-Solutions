#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int column, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c)
            return false;

        if (board[i][column] == c)
            return false;

        if (board[(row / 3) * 3 + i / 3][(column / 3) * 3 + i % 3] == c)
            return false;
    }
    return true;
}

bool Solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c) == true)
                    {
                        board[i][j] = c;

                        if (Solve(board) == true)
                            return true;

                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void SolveSudoku(vector<vector<char>> &board)
{
    Solve(board);
}

int main()
{

    return 0;
}
