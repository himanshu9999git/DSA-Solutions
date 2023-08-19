// https://leetcode.com/problems/numbers-with-same-consecutive-differences

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &ans, string s, int n, int k, int prev)
{
    if (s.length() == n)
    {
        ans.push_back(stoi(s));
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (prev - i == k)
        {
            s.push_back('0' + i);
            solve(ans, s, n, k, i);
            s.pop_back();
        }

        else if (i - prev == k)
        {
            s.push_back('0' + i);
            solve(ans, s, n, k, i);
            s.pop_back();
        }
    }
}
vector<int> numsSameConsecDiff(int n, int k)
{
    vector<int> ans;
    string s = "";

    for (int i = 1; i <= 9; i++)
    {
        s.push_back('0' + i);
        solve(ans, s, n, k, i);
        s.pop_back();
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> ans = numsSameConsecDiff(n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}