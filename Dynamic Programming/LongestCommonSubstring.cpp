#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int m, int n)
{
    int t[m + 1][n + 1];
    int mx = 0;
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }

            else
                t[i][j] = 0;

            mx = max(mx, t[i][j]);
        }
    }

    return mx;
}

int main()
{
    string x, y;

    cin >> x;
    cin >> y;

    int m = x.length();
    int n = y.length();

    cout << LCS(x, y, m, n);

    return 0;
}