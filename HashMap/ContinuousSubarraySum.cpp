#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        int m = sum % k;

        if ((m == 0 && i > 0) || (mp.find(m) != mp.end() && i - mp[m] > 1))
            return true;

        if (mp.find(m) == mp.end())
            mp[m] = i;
    }
    return false;
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

    int k;
    cin >> k;

    int ans = checkSubarraySum(nums, k);
    cout << ans;

    return 0;
}