#include <bits/stdc++.h>
using namespace std;

long long int count(long long int n)
{
    vector<int> arr = {3, 5, 10};
    vector<vector<long long>> dp(4, vector<long long>(n + 1, 0));

    if (n >= 3)
        dp[1][3] = 1;

    if (n >= 5)
        dp[2][5] = 1;

    if (n >= 10)
        dp[3][10] = 1;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] += dp[i][j - arr[i - 1]] + dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[3][n];
}

int main()
{

    long long int n;
    cin >> n;

    long long int ans = count(n);
    cout << ans;

    return 0;
}