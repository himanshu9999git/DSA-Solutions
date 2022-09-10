#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> arr, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

            else if (arr[i] > j)
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
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

    int target;
    cin >> target;

    if (subsetSum(arr, n, target))
        cout << "YES";

    else
        cout << "NO";

    return 0;
}