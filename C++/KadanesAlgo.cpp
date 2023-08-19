#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        ans = max(curr, ans);

        curr = max(curr, 0);
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

    int result = maxSubarray(nums);

    cout << result;
    return 0;
}