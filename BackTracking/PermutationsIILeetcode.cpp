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

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> v;
    vector<vector<int>> ans;
    vector<int> a;
    vector<int> vis(n, 0);

    solve(v, a, nums, vis, n);
    sort(v.begin(), v.end());

    ans.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
            ans.push_back(v[i]);
    }

    return ans;
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