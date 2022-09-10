#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
{
    vis[node] = 1;
    dfsvis[node] = 1;

    for (auto i : adj[node])
    {
        if (vis[i] == 0)
        {
            if (checkForCycle(i, vis, dfsvis, adj))
                return true;
        }
        else
        {
            if (dfsvis[i] == 1)
                return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> dfsvis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            if (checkForCycle(i, vis, dfsvis, adj))
                return true;
        }
    }
    return false;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(V, adj) << endl;
    }

    return 0;
}