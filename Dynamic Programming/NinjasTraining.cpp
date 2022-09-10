#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            points[i][j] += max(points[i - 1][(j + 1) % 3], points[i - 1][(j + 2) % 3]);
        }
    }

    return max(points[n - 1][0], max(points[n - 1][1], points[n - 1][2]));
}

int main()
{
    int n;
    
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }

    cout << maxPoints(points, n);

    return 0;
}