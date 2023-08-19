#include <bits/stdc++.h>
using namespace std;

int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<int> dis(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        for (auto j : edges)
        {
            int curr = j[0];
            int next = j[1];
            int dist = j[2];

            if (dist + dis[curr] < dis[next])
                dis[next] = dist + dis[curr];
        }
    }

    for (auto j : edges)
    {
        int curr = j[0];
        int next = j[1];
        int dist = j[2];

        if (dist + dis[curr] < dis[next])
            return 1;
    }
    return 0;
}

int main()
{

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> edges[i][j];
        }
    }

    int ans = isNegativeWeightCycle(n, edges);
    cout << ans;

    return 0;
}