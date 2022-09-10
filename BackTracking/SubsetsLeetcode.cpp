#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &v, vector<int> &arr, int n, int ind)
{
    if (ind == n)
    {
        ans.push_back(v);
        return;
    }

    solve(ans, v, arr, n, ind + 1);

    v.push_back(arr[ind]);
    solve(ans, v, arr, n, ind + 1);
    v.pop_back();
}

vector<vector<int>> subsets(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> v;

    solve(ans, v, arr, n, 0);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans = subsets(arr);

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