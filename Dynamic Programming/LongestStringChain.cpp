// https://leetcode.com/problems/longest-string-chain/

#include <bits/stdc++.h>
using namespace std;

static bool comp(string &s1, string &s2)
{
    return s1.length() < s2.length();
}

bool check(string &s1, string &s2)
{
    if (s1.length() != s2.length() + 1)
        return false;

    int i = 0;
    int j = 0;
    while (i < s1.length())
    {
        if (j < s2.length() && s1[i] == s2[j])
        {
            i++;
            j++;
        }

        else
            i++;
    }

    if (i == s1.length() && j == s2.length())
        return true;

    return false;
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int mx = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (check(words[j], words[i]))
            {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] += mx;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    int ans = longestStrChain(words);
    cout << ans;

    return 0;
}