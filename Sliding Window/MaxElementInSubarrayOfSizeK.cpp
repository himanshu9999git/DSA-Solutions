#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> dq;
    vector<int> v;

    int i = 0;
    while (i < k)
    {
        while (!dq.empty() && dq.front() < nums[i])
            dq.pop_front();

        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();

        dq.push_back(nums[i]);
        i++;
    }
    v.push_back(dq.front());

    while (i < n)
    {
        if (dq.front() == nums[i - k])
            dq.pop_front();

        while (!dq.empty() && dq.front() < nums[i])
            dq.pop_front();

        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();

        dq.push_back(nums[i]);
        v.push_back(dq.front());

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

    vector<int> ans = solve(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}