// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

#include <bits/stdc++.h>
using namespace std;

bool validPartition(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i > 1 && nums[i - 1] == nums[i - 2])
            dp[i] |= dp[i - 2];

        if (i > 2 && nums[i - 1] == nums[i - 2] && nums[i - 1] == nums[i - 3])
            dp[i] |= dp[i - 3];

        if (i > 2 && nums[i - 1] == nums[i - 2] + 1 && nums[i - 1] == nums[i - 3] + 2)
            dp[i] |= dp[i - 3];
    }
    return dp[n];
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

    int ans = validPartition(nums);
    cout << ans;

    return 0;
}