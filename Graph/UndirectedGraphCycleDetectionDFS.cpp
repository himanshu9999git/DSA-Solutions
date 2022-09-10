#include <bits/stdc++.h>
using namespace std;

bool checkcycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (checkcycle(i, node, vis, adj))
                return true;
        }
        else if (i != parent)
            return true;
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
            if (checkcycle(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}