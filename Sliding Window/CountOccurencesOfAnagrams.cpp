#include <bits/stdc++.h>
using namespace std;

int CountOccurences(string s, string a)
{
    int ans = 0;
    int k = a.length();

    unordered_map<char, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[a[i]]++;
    }
    int count = mp.size();

    int i = 0;
    for (i = 0; i < k - 1; i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                count--;
            }
        }
    }

    while (i < s.length())
    {
        if (mp.find(s[i]) != mp.end())
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                count--;
            }
        }
        if (count == 0)
            ans++;

        if (mp.find(s[i - k + 1]) != mp.end())
        {
            mp[s[i - k + 1]]++;
            if (mp[s[i - k + 1]] == 1)
            {
                count++;
            }
        }
        i++;
    }
    return ans;
}

int main()
{
    string s, a;
    cin >> s >> a;

    int ans = CountOccurences(s, a);
    cout << ans;

    return 0;
}