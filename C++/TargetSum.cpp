#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int index, int sum, int target, int n, int &ans)
{
    if ((index == n) && (sum == target))
    {
        ans++;
        return;
    }

    solve(nums, index + 1, sum + nums[index], target, n, ans);
    solve(nums, index + 1, sum - nums[index], target, n, ans);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int ans = 0;
    solve(nums, 0, 0, target, n, ans);

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

    int target;
    cin >> target;

    int ans = findTargetSumWays(nums, target);
    cout << ans;

    return 0;
}