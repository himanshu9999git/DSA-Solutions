#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k)
{
    int n = s.length();
    unordered_map<char, int> mp;
    int mx = -1;

    int i = 0;
    int j = 0;
    while (i < n)
    {
        mp[s[i]]++;
        if (mp.size() == k)
        {
            mx = max(mx, i - j + 1);
        }

        while (mp.size() > k)
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                mp.erase(s[j]);

            j++;
        }

        i++;
    }
    return mx;
}

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int ans = longestKSubstr(s, k);
    cout << ans;

    return 0;
}