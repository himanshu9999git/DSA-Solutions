#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, st, vis, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, st, vis, adj);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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

        vector<int> ans = topoSort(V, adj);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
    }

    return 0;
}