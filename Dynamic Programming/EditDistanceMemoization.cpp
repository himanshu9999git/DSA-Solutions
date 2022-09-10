// https://leetcode.com/problems/edit-distance/

#include <bits/stdc++.h>
using namespace std;

int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;

    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (word1[i] == word2[j])
        return dp[i][j] = solve(word1, word2, i - 1, j - 1, dp);

    else
        return dp[i][j] = 1 + min(solve(word1, word2, i, j - 1, dp),
                                  min(solve(word1, word2, i - 1, j, dp), solve(word1, word2, i - 1, j - 1, dp)));
}

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(word1, word2, m - 1, n - 1, dp);
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    int ans = minDistance(word1, word2);
    cout << ans;

    return 0;
}