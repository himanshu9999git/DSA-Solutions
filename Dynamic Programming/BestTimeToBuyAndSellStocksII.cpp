// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
                dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

            else
                dp[i][j] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }
    }

    return dp[0][1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int ans = maxProfit(prices);
    cout << ans;

    return 0;
}