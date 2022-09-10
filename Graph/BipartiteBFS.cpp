#include <bits/stdc++.h>
using namespace std;

bool checkForBipartite(int V, vector<int> adj[], vector<int> &color)
{
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            queue<pair<int, int>> q;
            q.push({i, 0});

            while (!q.empty())
            {
                int node = q.front().first;
                int col = q.front().second;
                q.pop();

                for (auto j : adj[node])
                {
                    if (color[j] == -1)
                    {
                        color[j] = 1 - color[node];
                        q.push({j, color[j]});
                    }

                    else
                    {
                        if (color[j] == color[node])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    if (!checkForBipartite(V, adj, color))
        return false;

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
