// https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/

#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int sum = 0;

    for (int i = 0; i < m; i++)
        sum += matrix[i][0];

    for (int j = 1; j < n; j++)
        sum += matrix[0][j];

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
                continue;

            matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j]));
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int ans = countSquares(matrix);
    cout << ans;

    return 0;
}