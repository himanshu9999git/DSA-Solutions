#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n, 1);
    int ans = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        int mx = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
                mx = max(v[j], mx);
        }
        v[i] += mx;
        ans = max(v[i], ans);
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

    int ans = lengthOfLIS(nums);
    cout << ans;

    return 0;
}