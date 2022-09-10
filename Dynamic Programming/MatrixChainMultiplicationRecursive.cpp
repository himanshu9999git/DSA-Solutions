#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int i, int j)
{
    if (i >= j)
        return 0;

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(nums, i, k) + solve(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j];

        mn = min(temp, mn);
    }
    return mn;
}

int MCM(vector<int> nums)
{
    int n = nums.size();
    int ans = solve(nums, 1, n - 1);
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

    int ans = MCM(nums);
    cout << ans;

    return 0;
}