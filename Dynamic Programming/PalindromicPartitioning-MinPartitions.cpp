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

int palindromicPartition(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX - 1 && isPalindrome(s.substr(j, i - j)))
                dp[i] = min(dp[i], 1 + dp[j]);
        }
    }
    return dp[n];
}

int main()
{

    string s;
    cin >> s;

    int ans = palindromicPartition(s);
    cout << ans;

    return 0;
}