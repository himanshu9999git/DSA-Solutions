#include <bits/stdc++.h>
using namespace std;

vector<int> LDS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n, 1);
    sort(nums.begin(), nums.end());

    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i].push_back(nums[i]);
    }

    int ans = 0;
    int finalind = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int mx = 0;
        int ind = 0;

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] % nums[i] == 0)
            {
                if (mx < v[j])
                {
                    mx = v[j];
                    ind = j;
                }
            }
        }
        v[i] += mx;
        if (mx > 0)
        {
            for (int x = 0; x < dp[ind].size(); x++)
                dp[i].push_back(dp[ind][x]);
        }

        if (ans < v[i])
        {
            ans = v[i];
            finalind = i;
        }
    }
    return dp[finalind];
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

    vector<int> ans = LDS(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}