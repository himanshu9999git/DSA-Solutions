// https://leetcode.com/problems/unique-paths-ii

#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1 - obstacleGrid[0][0];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;

            if (obstacleGrid[i - 1][j - 1] == 1)
                dp[i][j] = 0;

            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
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