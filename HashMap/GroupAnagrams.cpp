#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    vector<vector<string>> ans;
    map<string, vector<string>> mp;

    for (int i = 0; i < n; i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());

        mp[s].push_back(strs[i]);
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans.push_back(i->second);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}