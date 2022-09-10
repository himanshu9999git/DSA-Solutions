#include <bits/stdc++.h>
using namespace std;

int minimumSubsetSumDifference(vector<int> nums)
{
    int n = nums.size();
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += nums[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(range + 1, 0));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans;
    for (int i = range / 2; i >= 0; i--)
    {
        if (dp[n][i] == 1)
        {
            ans = range - 2 * i;
            break;
        }
    }

    return ans;
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

    int ans = minimumSubsetSumDifference(nums);
    cout << ans;

    return 0;
}