#include <bits/stdc++.h>
using namespace std;

int static t[1000][1000];

int LCS(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (t[m][n] != -1)
        return t[m][n];

    else
    {
        if (x[m] == y[n])
            return t[m][n] = 1 + LCS(x, y, m - 1, n - 1);

        else
            return t[m][n] = max(LCS(x, y, m - 1, n), LCS(x, y, m, n - 1));
    }
}

int main()
{
    memset(t, -1, sizeof(t));

    string x, y;

    cin >> x;
    cin >> y;

    int m = x.length();
    int n = y.length();

    cout << LCS(x, y, m, n);

    return 0;
}