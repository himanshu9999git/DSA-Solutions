#include <bits/stdc++.h>
using namespace std;

int cuttingStick(int fi, int li, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (fi > li)
        return 0;

    if (dp[fi][li] != -1)
        return dp[fi][li];

    int mn = INT_MAX;
    for (int i = fi; i <= li; i++)
    {
        int cost = cuts[li + 1] - cuts[fi - 1] + cuttingStick(fi, i - 1, cuts, dp) + cuttingStick(i + 1, li, cuts, dp);

        mn = min(mn, cost);
    }
    return dp[fi][li] = mn;
}

int minCost(int len, vector<int> &cuts)
{
    int n = cuts.size();
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(len);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
    int ans = cuttingStick(1, n, cuts, dp);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> cuts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cuts[i];
    }

    int len;
    cin >> len;

    cout << minCost(len, cuts);
    return 0;
}