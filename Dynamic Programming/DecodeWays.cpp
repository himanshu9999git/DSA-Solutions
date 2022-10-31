#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, 1);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            dp[i] = 0;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int a = stoi(s.substr(i, 1));
        int x = 0;
        if (a > 0)
        {
            x += dp[i] * dp[i + 1];
        }

        int b = stoi(s.substr(i, 2));
        if (b > 0 && b <= 26)
        {
            x += dp[i] * dp[i + 2];
        }
        dp[i] = x;
    }
    return dp[0];
}

int main()
{

    string s;
    cin >> s;

    int ans = numDecodings(s);
    cout << ans;

    return 0;
}