// https://leetcode.com/problems/max-consecutive-ones-iii/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int count = 0;

    while (j < n)
    {
        if (nums[j] == 0)
            k--;

        if (k < 0)
        {
            if (nums[i] == 0)
                k++;

            i++;
        }
        j++;

        count = max(count, j - i);
    }
    return count;
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

    int ans = longestOnes(nums, k);
    cout << ans;

    return 0;
}