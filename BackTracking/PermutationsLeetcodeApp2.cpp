#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &v, vector<int> &nums, int n, int ind)
{
    if (ind == n)
    {
        v.push_back(nums);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        swap(nums[i], nums[ind]);
        solve(v, nums, n, ind + 1);
        swap(nums[i], nums[ind]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> v;
    solve(v, nums, n, 0);

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