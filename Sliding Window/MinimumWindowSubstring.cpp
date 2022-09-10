// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int mn = INT_MAX;

    unordered_map<char, int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[t[i]]++;
    }

    int count = mp.size();
    int i = 0;
    int j = 0;
    bool flag = false;

    int st;
    int end;

    while (j < n)
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if (mp[s[j]] == 0)
                count--;
        }

        while (i <= j && count == 0)
        {
            flag = true;
            if (mn > j - i + 1)
            {
                st = i;
                end = j;
                mn = j - i + 1;
            }
            if (mp.find(s[i]) != mp.end())
            {
                mp[s[i]]++;

                if (mp[s[i]] > 0)
                    count++;
            }
            i++;
        }
        j++;
    }

    string ans = "";
    if (!flag)
        return ans;

    s = s.substr(st, end - st + 1);
    return s;
}

int main()
{

    string s, t;
    cin >> s;
    cin >> t;

    string ans = minWindow(s, t);
    cout << ans;

    return 0;
}