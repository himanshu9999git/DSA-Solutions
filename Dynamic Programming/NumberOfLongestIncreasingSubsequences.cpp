#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);

    int ans = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int mx = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
                mx = max(dp[j], mx);
        }
        dp[i] += mx;
        ans = max(ans, dp[i]);

        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i] && dp[j] == dp[i] - 1)
                count += cnt[j];
        }
        if (count > 1)
            cnt[i] = count;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == ans)
            sum += cnt[i];
    }

    return sum;
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

    int ans = findNumberOfLIS(nums);
    cout << ans;

    return 0;
}