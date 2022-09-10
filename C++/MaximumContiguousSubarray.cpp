#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (sum < 0)
            sum = 0;

        sum += nums[i];
        mx = max(sum, mx);
    }
    return mx;
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

    int ans = maxSubArray(nums);
    cout << ans;

    return 0;
}