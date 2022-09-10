#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, bool graph[101][101], int N, vector<int> &color, int i)
{
    for (int j = 0; j < N; j++)
    {
        if ((j != node) && graph[j][node] == 1 && color[j] == i)
            return false;
    }
    return true;
}
bool Solve(int node, bool graph[101][101], int m, int N, vector<int> &color)
{
    if (node == N)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, graph, N, color, i) == true)
        {
            color[node] = i;

            if (Solve(node + 1, graph, m, N, color) == true)
                return true;

            color[node] = 0;
        }
    }
    return false;
}

bool GraphColoring(bool graph[101][101], int m, int N)
{
    vector<int> color(N, 0);
    if (Solve(0, graph, m, N, color) == true)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}