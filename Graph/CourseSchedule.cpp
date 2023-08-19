#include <bits/stdc++.h>
using namespace std;

// DFS METHOD

bool dfs(vector<vector<int>> adj, vector<int> &vis, int i, vector<int> &curr)
{
    vis[i] = 1;
    curr[i] = 1;
    for (auto node : adj[i])
    {
        if (curr[node])
            return true;
        else if (!vis[node])
            if (dfs(adj, vis, node, curr))
                return true;
    }
    curr[i] = 0;
    return false;
}
bool canFinish(int n, vector<vector<int>> &pre)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < pre.size(); i++)
    {
        adj[pre[i][0]].push_back(pre[i][1]);
    }
    vector<int> vis(n, 0);
    vector<int> curr(n, 0);
    int pa = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, i, curr))
                return false;
        }
    }
    return true;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    return 0;
}