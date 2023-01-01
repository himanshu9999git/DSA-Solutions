// https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &v)
{
    int m = v.size();
    int n = v[0].size();

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int s = v[i + 1][j];
            int sw = s;
            int se = s;

            if (j > 0)
                se = v[i + 1][j - 1];

            if (j < n - 1)
                sw = v[i + 1][j + 1];

            v[i][j] += min(s, min(se, sw));
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
        mn = min(v[0][i], mn);

    return mn;
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

    int ans = minFallingPathSum(matrix);
    cout << ans;

        return 0;
}