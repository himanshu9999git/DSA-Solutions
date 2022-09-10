#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, vector<vector<int>> &dp, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(nums, dp, i, k) + solve(nums, dp, k + 1, j) + nums[i - 1] * nums[k] * nums[j];

        mn = min(temp, mn);
    }
    return dp[i][j] = mn;
}

int MCM(vector<int> nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    solve(nums, dp, 1, n - 1);
    return dp[1][n - 1];
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

    int ans = MCM(nums);
    cout << ans;

    return 0;
}