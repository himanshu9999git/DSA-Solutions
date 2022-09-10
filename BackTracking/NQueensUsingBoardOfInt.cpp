#include <bits/stdc++.h>
using namespace std;

void Solve(int col, vector<int> &board, vector<vector<int>> &ans, int n, vector<int> &LeftRow, vector<int> &LowerDiagonal, vector<int> &UpperDiagonal)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (LeftRow[row] == 0 && LowerDiagonal[row + col] == 0 && UpperDiagonal[n + col - row - 1] == 0)
        {
            board.push_back(row+1);
            LeftRow[row] = 1;
            LowerDiagonal[row + col] = 1;
            UpperDiagonal[n + col - row - 1] = 1;

            Solve(col + 1, board, ans, n, LeftRow, LowerDiagonal, UpperDiagonal);

            board.pop_back();
            LeftRow[row] = 0;
            LowerDiagonal[row + col] = 0;
            UpperDiagonal[n + col - row - 1] = 0;
        }
    }
}

vector<vector<int>> SolveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<int> board;

    vector<int> LeftRow(n, 0);
    vector<int> LowerDiagonal(2 * n - 1, 0);
    vector<int> UpperDiagonal(2 * n - 1, 0);

    Solve(0, board, ans, n, LeftRow, LowerDiagonal, UpperDiagonal);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans;
    ans = SolveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}