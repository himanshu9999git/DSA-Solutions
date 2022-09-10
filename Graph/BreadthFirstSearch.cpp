#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> bfs(V);
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto j : adj[node])
                {
                    if (!vis[j])
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main()
{

    return 0;
}