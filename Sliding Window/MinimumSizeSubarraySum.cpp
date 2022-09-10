// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();

    int i = 0, j = 0;
    int sum = 0;
    int mn = n;
    bool flag = false;

    while (j < n)
    {
        if (sum < target)
        {
            sum += nums[j];
            j++;
        }

        if (sum >= target)
        {
            flag = true;
            while (sum >= target)
            {
                mn = min(mn, j - i);

                sum -= nums[i];
                i++;
            }
        }
    }
    if (flag == false)
        return 0;

    return mn;
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

    int ans = minSubArrayLen(target, nums);
    cout << ans;

    return 0;
}