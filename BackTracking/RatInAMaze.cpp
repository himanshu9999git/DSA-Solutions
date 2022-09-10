#include <bits/stdc++.h>
using namespace std;

void Solve(int row, int col, vector<vector<int>> &m, int n, vector<vector<int>> &vis, vector<string> &ans, string &s, int dy[], int dx[])
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(s);
        return;
    }

    string dir = "DLRU";
    for (int a = 0; a < 4; a++)
    {
        int i = row + dy[a];
        int j = col + dx[a];

        if (i >= 0 && j >= 0 && i < n && j < n && m[i][j] == 1 && vis[i][j] == 0)
        {
            vis[row][col] = 1;
            s.push_back(dir[a]);

            Solve(i, j, m, n, vis, ans, s, dy, dx);
            vis[row][col] = 0;
            s.pop_back();
        }
    }
}

vector<string> FindPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    string s = "";

    int dy[] = {+1, 0, 0, -1};
    int dx[] = {0, -1, +1, 0};

    if (m[0][0] == 1)
        Solve(0, 0, m, n, vis, ans, s, dy, dx);

    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;

    vector<string> ans = FindPath(m, n);

    for (int i = 0; i < 4; i++)
    {
        cout << ans[i]<<endl;
    }

    return 0;
}