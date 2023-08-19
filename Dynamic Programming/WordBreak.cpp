#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(n+1, 0);
    
    dp[0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(dp[j] && dict.count(s.substr(j, i - j)))
                dp[i] = 1;
        }
    }
    return dp[n];
}

int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> wordDict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordDict[i];
    }

    bool ans = wordBreak(s, wordDict);
    cout << ans;

    return 0;
}