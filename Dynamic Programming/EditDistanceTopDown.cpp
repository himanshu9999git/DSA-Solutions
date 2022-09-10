// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < m + 1; i++)
        dp[i][0] = i;

    for (int j = 1; j < n + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
        }
    }

    return dp[m][n];
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    int ans = minDistance(word1, word2);
    cout << ans;

    return 0;
}