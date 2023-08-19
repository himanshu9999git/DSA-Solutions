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
        if (i > ind && nums[i] == nums[ind])
            continue;

        swap(nums[i], nums[ind]);
        solve(v, nums, n, ind + 1);
    }

    for (int i = n - 1; i > ind; i--)
    {
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    solve(v, nums, n, 0);

    return v;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;

    vector<vector<int>> ans;
    ans = permuteUnique(a);

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