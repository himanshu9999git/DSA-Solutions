#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
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

    int target;
    cin >> target;

    int ans = solve(nums, target);
    cout << ans;

    return 0;
}