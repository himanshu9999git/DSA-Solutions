//  https://leetcode.com/problems/word-break-ii

#include <bits/stdc++.h>
using namespace std;

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<vector<string>> st(n + 1);
    vector<int> dp(n + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && dict.count(s.substr(j, i - j)))
            {
                dp[i] = 1;
                for (int k = 0; k < st[j].size(); k++)
                {
                    string t = st[j][k] + ' ';
                    t += s.substr(j, i - j);
                    st[i].push_back(t);
                }

                if (st[j].size() == 0)
                {
                    string t = s.substr(j, i - j);
                    st[i].push_back(t);
                }
            }
        }
    }
    return st[n];
}

int main()
{

    int n;
    cin >> n;

    vector<string> wordDict(n);
    for (int i = 0; i < n; i++)
        cin >> wordDict[i];

    string s;
    cin >> s;

    vector<string> ans = wordBreak(s, wordDict);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}