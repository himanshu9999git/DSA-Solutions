#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    int curr = 0;
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < n)
    {
        while (i < n && count < 2)
        {
            if (nums[i] == 0)
                count++;

            i++;
        }

        curr = i - j - 1;
        if (count == 2)
            curr--;

        ans = max(curr, ans);

        while (count > 1)
        {
            if (nums[j] == 0)
                count--;

            j++;
        }
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

    int ans = longestSubarray(nums);
    cout << ans;

    return 0;
}