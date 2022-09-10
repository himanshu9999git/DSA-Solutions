#include <bits/stdc++.h>
using namespace std;

void solve(string &str, string &s, int n, int ind, int k)
{
    if (str > s)
    {
        s = str;
    }

    if (k == 0 || ind == n)
        return;

    for (int i = ind + 1; i < n; i++)
    {
        swap(str[i], str[ind]);
        solve(str, s, n, ind + 1, k - 1);
        swap(str[i], str[ind]);
    }
}

string findMaximumNum(string str, int k)
{
    int n = str.length();
    string s = str;
    solve(str, s, n, 0, k);

    return s;
}

int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    string ans = findMaximumNum(s, k);
    cout << ans;

    return 0;
}




class Solution
{
    public:
    
    void solve(string &str, string &s, int n, int ind, int k)
{
    if (str>s)
    {
        s = str;
    }
    
    if(k==0 || ind == n)
        return;

    for (int i = ind + 1; i < n; i++)
    {
        swap(str[i], str[ind]);
        solve(str, s, n, ind + 1, k-1);
        swap(str[i], str[ind]);
    }
}

    string findMaximumNum(string str, int k)
    {
        int n = str.length();
        string s = str;
        solve(str, s, n, 0, k);

    return s;
    }
};