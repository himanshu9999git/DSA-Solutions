#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> v;

    int i = 0;
    queue<int> q;

    while (i + 1 < k)
    {
        while (!q.empty() && q.front() <= nums[i])
            q.pop();

        q.push(nums[i]);
        i++;
    }

    while (i < n)
    {
        while (!q.empty() && q.front() <= nums[i])
            q.pop();

        q.push(nums[i]);
        v.push_back(q.front());

        if (q.front() == nums[i - k + 1])
            q.pop();

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