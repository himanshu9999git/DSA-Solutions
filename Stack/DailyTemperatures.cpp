// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temp)
{
    int n = temp.size();
    vector<int> ans;
    stack<pair<int, int>> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first <= temp[i])
            st.pop();

        if (st.empty())
            ans.push_back(0);

        else
            ans.push_back(st.top().second - i);

        st.push({temp[i], i});
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }

    vector<int> ans = dailyTemperatures(temp);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}