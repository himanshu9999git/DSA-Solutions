#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storedfs)
{
    storedfs.push_back(node);
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, storedfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> storedfs;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, storedfs);
        }
    }
    return storedfs;
}

int main()
{

    return 0;
}