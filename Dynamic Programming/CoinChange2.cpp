#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int sum)
{
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int j = 0; j <= sum; j++)
        dp[0][j] = INT_MAX - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][sum] == INT_MAX - 1)
        return -1;

    return dp[n][sum];
}

int main()
{
    int n, sum;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cin >> sum;

    cout << coinChange(coins, sum);

    return 0;
}