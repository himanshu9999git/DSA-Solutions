#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
    {
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
        }
        return mx;
    }

    if (n == 3)
        return max(nums[n - 2], nums[n - 3] + nums[n - 1]);

    //  Using 1-D DP

    // vector<int> dp(n, 0);
    //     dp[n-1] = nums[n-1];
    //     dp[n-2] = nums[n-2];
    //     dp[n-3] = nums[n-3] + nums[n-1];
    //     for(int i=n-4; i>=0; i--)
    //     {
    //         dp[i] = max(dp[i+2], dp[i+3]) + nums[i];
    //     }
    //     return max(dp[0], dp[1]);

    int prev2 = nums[n - 1];
    int prev1 = nums[n - 2];
    int avoid = nums[n - 3] + prev2;
    int curr;

    for (int i = n - 4; i >= 0; i--)
    {
        int curr = nums[i] + max(prev2, prev1);
        prev2 = prev1;
        prev1 = avoid;
        avoid = curr;
    }

    return max(avoid, prev1);
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

    cout << rob(nums);
    return 0;
}