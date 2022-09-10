#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return false;

        start++;
        end--;
    }
    return true;
}

void solve(string s, vector<vector<string>> &ans, vector<string> &v, int n, int ind)
{
    if (ind == n)
    {
        ans.push_back(v);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (isPalindrome(s, ind, i))
        {
            v.push_back(s.substr(ind, i - ind + 1));
            solve(s, ans, v, n, i + 1);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    int n = s.length();
    vector<vector<string>> ans;
    vector<string> v;

    solve(s, ans, v, n, 0);
    return ans;
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> ans = partition(s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}