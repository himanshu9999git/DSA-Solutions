// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int cap, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(cap + 1, 0)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k < cap + 1; k++)
            {
                if (j == 1)
                    dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);

                else
                    dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
            }
        }
    }

    return dp[0][1][cap];
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

    int cap;
    cin >> cap;

    int ans = maxProfit(cap, prices);
    cout << ans;

    return 0;
}