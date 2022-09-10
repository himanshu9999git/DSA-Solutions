#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int n = s.length();
    int m = p.length();

    vector<int> ans;
    if (m > n)
        return ans;

    unordered_map<char, int> mp;
    for (int i = 0; i < m; i++)
        mp[p[i]]++;

    int i = 0;
    int j = 0;

    int count = mp.size();

    while (j < m - 1)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
                count--;
        }
        j++;
    }

    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
                count--;
        }

        if (count == 0)
            ans.push_back(i);

        if (mp.find(s[i]) != mp.end())
        {
            if (mp[s[i]] == 0)
                count++;

            mp[s[i]]++;
        }

        i++;
        j++;
    }
    return ans;
}

int main()
{

    string s, p;
    cin >> s >> p;

    vector<int> ans = findAnagrams(s, p);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}