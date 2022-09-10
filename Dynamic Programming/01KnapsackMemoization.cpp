#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] <= w)
        return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));

    else if (wt[n - 1] > w)
        return dp[n][w] = knapsack(wt, val, w, n - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> wt(n, 0);
    vector<int> val(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, w, n);
    return 0;
}