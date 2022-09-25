#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
        if (s[start] != s[end])
            return false;

        start++;
        end--;
    }
    return true;
}

bool palindromepair(vector<string> &words)
{
    int n = words.size();
    unordered_map<string, int> mp;
    mp[words[0]] = 0;

    for (int i = 0; i < n; i++)
    {
        mp[words[i]] = i;
    }

    if (mp.find("") != mp.end())
    {
        for (int i = 0; i < n; i++)
        {
            if (words[i] != "" && isPalindrome(words[i]))
            {
                return true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (words[i] == "")
            continue;

        string s1 = words[i];
        reverse(s1.begin(), s1.end());

        for (int j = 1; j <= words[i].length(); j++)
        {
            string s2 = words[i].substr(0, j);
            string s3 = s2;
            reverse(s3.begin(), s3.end());

            if (mp.find(s3) != mp.end() && mp[s3] != i)
            {
                if (isPalindrome(words[i] + s3))
                    return true;
            }
        }

        for (int j = 1; j <= s1.length(); j++)
        {
            string s2 = s1.substr(0, j);

            if (mp.find(s2) != mp.end() && mp[s2] != i)
            {
                if (isPalindrome(s2 + words[i]))
                    return true;
            }
        }
    }
    return false;
}

int main()
{

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    int ans = palindromepair(words);
    cout << ans;

    return 0;
}