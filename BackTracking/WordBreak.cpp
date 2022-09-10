#include <bits/stdc++.h>
using namespace std;

bool solve(string s, vector<string> &wordDict, string t, int n)
{
    if (t == s)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (((t + wordDict[i]).length() <= s.length()) && (t + wordDict[i]) == s.substr(0, (t + wordDict[i]).length()))
        {
            if (solve(s, wordDict, t + wordDict[i], n))
                return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = wordDict.size();
    string t = "";

    bool ans = solve(s, wordDict, t, n);
    return ans;
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