#include <bits/stdc++.h>
using namespace std;

void findans(vector<int> &c, vector<vector<int>> &ans, vector<int> &v, int sum, int target, int n, int k)
{
    if (sum == target)
    {
        ans.push_back(v);
        return;
    }

    if (sum > target)
        return;

    for (int i = k; i < n; i++)
    {
        v.push_back(c[i]);
        findans(c, ans, v, sum + c[i], target, n, i);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    int n = candidates.size();
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> v;

    findans(candidates, ans, v, 0, target, n, 0);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> candidates(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> ans = combinationSum(candidates, target);
    
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