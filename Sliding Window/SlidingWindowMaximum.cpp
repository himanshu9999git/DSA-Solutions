// https://leetcode.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> v;

    int i = 0;
    list<int> l;

    while (i + 1 < k)
    {
        while (!l.empty() && l.back() < nums[i])
            l.pop_back();

        l.push_back(nums[i]);
        i++;
    }

    while (i < n)
    {
        while (!l.empty() && l.back() < nums[i])
            l.pop_back();

        l.push_back(nums[i]);
        v.push_back(l.front());

        if (l.front() == nums[i - k + 1])
            l.pop_front();

        i++;
    }
    return v;
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

    vector<int> ans = maxSlidingWindow(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}