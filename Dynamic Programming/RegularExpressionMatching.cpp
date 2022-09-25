// https://leetcode.com/problems/regular-expression-matching/

#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;
    for (int j = 1; j < n + 1; j++)
    {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else if (p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];

            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2];

                if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int main()
{

    string s, p;
    cin >> s >> p;

    int ans = isMatch(s, p);
    cout << ans;

    return 0;
}