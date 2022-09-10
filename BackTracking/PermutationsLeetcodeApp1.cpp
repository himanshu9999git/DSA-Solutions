#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &v, vector<int> &a, vector<int> nums, vector<int> &vis, int n)
{
    if (a.size() == n)
    {
        v.push_back(a);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            a.push_back(nums[i]);
            vis[i] = 1;

            solve(v, a, nums, vis, n);
            vis[i] = 0;
            a.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> v;
    vector<int> a;
    vector<int> vis(n, 0);

    solve(v, a, nums, vis, n);

    return v;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans = permute(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}