// https://leetcode.com/problems/burst-balloons/

#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i > j)
                continue;

            int mx = INT_MIN;
            for (int ind = i; ind <= j; ind++)
                mx = max(mx, nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j]);

            dp[i][j] = mx;
        }
    }
    return dp[1][n];
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = maxCoins(nums);
    cout << ans;

    return 0;
}