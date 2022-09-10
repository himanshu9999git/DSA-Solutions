#include <bits/stdc++.h>
using namespace std;

bool checkcycle(int i, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto j : adj[node])
        {
            if (!vis[j])
            {
                q.push({j, node});
                vis[j] = 1;
            }
            else if (parent != j)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (checkcycle(i, adj, vis))
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}