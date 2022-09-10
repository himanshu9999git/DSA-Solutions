// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t)
{
    int m = s.length();
    int n = t.length();

    vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return (int)dp[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;

    int ans = numDistinct(s, t);
    cout << ans;

    return 0;
}