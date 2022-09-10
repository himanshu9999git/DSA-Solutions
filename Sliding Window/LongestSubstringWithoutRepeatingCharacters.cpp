// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int n = s.length();

    int i = 0, j = 0;
    int mx = 0;
    while (j < n)
    {
        mp[s[j]]++;

        if (mp[s[j]] > 1)
        {
            while (mp[s[j]] != 1)
            {
                mp[s[i]]--;
                i++;
            }
        }
        j++;

        mx = max(mx, j - i);
    }
    return mx;
}

int main()
{
    string s;
    cin >> s;

    int ans = lengthOfLongestSubstring(s);
    cout << ans;

    return 0;
}