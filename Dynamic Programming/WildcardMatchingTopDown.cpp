// https://leetcode.com/problems/wildcard-matching/

#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    int m = s.length();
    int n = p.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    int flag;
    for (int j = 1; j < n + 1; j++)
    {
        flag = 1;
        for (int a = 1; a < j + 1; a++)
        {
            if (p[a - 1] != '*')
            {
                flag = 0;
                break;
            }
        }

        dp[0][j] = flag;
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if ((s[i - 1] == p[j - 1]) || (p[j - 1] == '?'))
                dp[i][j] = dp[i - 1][j - 1];

            else if (p[j - 1] == '*')
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{

    string s, p;
    cin >> s;
    cin >> p;

    bool ans = isMatch(s, p);
    cout << ans;

    return 0;
}