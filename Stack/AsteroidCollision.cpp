#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &ast)
{
    stack<int> st;
    vector<int> ans;

    int n = ast.size();
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || ast[i] >= 0)
            st.push(ast[i]);

        else
        {
            while (!st.empty() && st.top() >= 0 && st.top() < abs(ast[i]))
                st.pop();

            if (st.empty())
                st.push(ast[i]);

            else if (st.top() == abs(ast[i]))
                st.pop();

            else if (st.top() < 0)
                st.push(ast[i]);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> ast(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ast[i];
    }

    vector<int> ans = asteroidCollision(ast);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}