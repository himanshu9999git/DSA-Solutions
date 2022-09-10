// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int n = prices.size();
    int mx = prices[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        ans = max(ans, mx - prices[i]);
        mx = max(prices[i], mx);
    }
    return ans;
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
