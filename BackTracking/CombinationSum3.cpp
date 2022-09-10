#include <bits/stdc++.h>
using namespace std;

void findans(vector<vector<int>> &ans, vector<int> &v, int sum, int target, int n, int k)
{
    if (v.size() == n)
    {
        if (sum == target)
            ans.push_back(v);

        return;
    }

    for (int i = k; i < 10; i++)
    {
        v.push_back(i);
        findans(ans, v, sum + i, target, n, i + 1);
        v.pop_back();
    }
}

vector<vector<int>> combinationSum3(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;

    findans(ans, v, 0, k, n, 1);
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> ans = combinationSum3(n, k);

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