#include <bits/stdc++.h>
using namespace std;

int RodCutting(vector<int> length, vector<int> price, int len, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(len + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < len + 1; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][len];
}

int main()
{
    int n, len;
    cin >> n;

    vector<int> length(n, 0);
    vector<int> price(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> length[i];
    }

    cin >> len;

    cout << RodCutting(length, price, len, n);
    return 0;
}