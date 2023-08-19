#include <bits/stdc++.h>
using namespace std;

int solve(int n, int l, string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < l; i++)
        mp[s[i]] = i;

    int ans = 0;
    for (int i = 0; i < l; i++)
        ans = max(ans, mp[s[i]] - i - 2 * n);

    return ans;
}

int main()
{

    int l;
    cin >> l;

    string s;
    cin >> s;

    int n;
    cin >> n;

    int ans = solve(n, l, s);

    return 0;
}