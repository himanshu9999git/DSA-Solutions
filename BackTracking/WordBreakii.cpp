#include <bits/stdc++.h>
using namespace std;

void solve(string s, vector<string> &wordDict, string t, vector<vector<int>> &ans, vector<int> &v, int n)
{
    if (t == s)
    {
        ans.push_back(v);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (((t + wordDict[i]).length() <= s.length()) && (t + wordDict[i]) == s.substr(0, (t + wordDict[i]).length()))
        {
            v.push_back(i);
            solve(s, wordDict, t + wordDict[i], ans, v, n);
            v.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    int n = wordDict.size();
    
    string t = "";
    vector<int> v;
    vector<vector<int>> ans;

    solve(s, wordDict, t, ans, v, n);

    vector<string> sol;
    for (int i = 0; i < ans.size(); i++)
    {
        string x = "";
        for (int j = 0; j < ans[i].size(); j++)
        {
            x += wordDict[ans[i][j]];

            if (j < ans[i].size() - 1)
                x.push_back(' ');
        }
        sol.push_back(x);
    }
    return sol;
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

    vector<string> ans = wordBreak(s, wordDict);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}