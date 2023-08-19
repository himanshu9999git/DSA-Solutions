// https://leetcode.com/problems/unique-paths-ii

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || obstacleGrid[i][j] == 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == 0 && j == 0)
        return 1;

    return dp[i][j] = dfs(obstacleGrid, i, j - 1, dp, m, n) + dfs(obstacleGrid, i - 1, j, dp, m, n);
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return dfs(obstacleGrid, m - 1, n - 1, dp, m, n);
}

int main()
{

    int m, n;
    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> obstacleGrid[i][j];
        }
    }

    int ans = uniquePathsWithObstacles(obstacleGrid);
    cout << ans;

    return 0;
}