#include <bits/stdc++.h>
using namespace std;

bool goLeft(int i, int j, int m, int n)
{
    if (j > 0)
        return true;

    return false;
}

bool goRight(int i, int j, int m, int n)
{
    if (j < m - 1)
        return true;

    return false;
}

bool goUp(int i, int j, int m, int n)
{
    if (i > 0)
        return true;

    return false;
}

bool goDown(int i, int j, int m, int n)
{
    if (i < n - 1)
        return true;

    return false;
}

bool findans(vector<vector<char>> &board, string word, vector<vector<int>> &vis, int i, int j, int k, int m, int n)
{
    if (k == word.length())
        return true;

    if (vis[i][j] == 0)
    {
        vis[i][j] = 1;
        if (board[i][j] == word[k])
        {
            if (goLeft(i, j, m, n))
            {
                if (vis[i][j - 1] == 0)
                {
                    vis[i][j - 1] = 1;
                    findans(board, word, vis, i, j - 1, k + 1, m, n);
                    vis[i][j - 1] = 0;
                }
            }

            if (goRight(i, j, m, n))
            {
                if (vis[i][j + 1] == 0)
                {
                    vis[i][j + 1] = 1;
                    findans(board, word, vis, i, j + 1, k + 1, m, n);
                    vis[i][j + 1] = 0;
                }
            }

            if (goUp(i, j, m, n))
            {
                if (vis[i - 1][j] == 0)
                {
                    vis[i - 1][j] = 1;
                    findans(board, word, vis, i - 1, j, k + 1, m, n);
                    vis[i - 1][j] = 0;
                }
            }

            if (goDown(i, j, m, n))
            {
                if (vis[i + 1][j] == 0)
                {
                    vis[i + 1][j] = 1;
                    findans(board, word, vis, i + 1, j, k + 1, m, n);
                    vis[i + 1][j] = 0;
                }
            }
        }
        vis[i][j] = 0;
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int a = 0; a < m; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (findans(board, word, vis, a, b, 0, m, n))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}