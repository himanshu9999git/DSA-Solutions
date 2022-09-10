#include <bits/stdc++.h>
using namespace std;

bool checkForBipartite(int node, vector<int> adj[], vector<int> &vis)
{
    for (auto i : adj[node])
    {
        if (vis[i] == -1)
        {
            vis[i] = 1 - vis[node];
            if (!checkForBipartite(i, adj, vis))
                return false;
        }
        else
        {
            if (vis[i] == vis[node])
                return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> vis(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == -1)
        {
            vis[i] = 0;
            if (!checkForBipartite(i, adj, vis))
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(n, adj))
        cout << "Yes";

    else
        cout << "No";

    return 0;
}