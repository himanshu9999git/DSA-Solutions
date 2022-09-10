#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);

            else if (wt[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
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