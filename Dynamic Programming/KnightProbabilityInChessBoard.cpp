// https://leetcode.com/problems/knight-probability-in-chessboard

#include <bits/stdc++.h>
using namespace std;

double solve(vector<vector<vector<double>>> &dp, int n, int k, int r, int c, vector<double> x, vector<double> y)
{
    if (r < 0 || c < 0 || r >= n || c >= n)
        return 0;

    if (k == 0)
        return 1;

    if (dp[r][c][k])
        return dp[r][c][k];

    double curr = 0;
    for (int i = 0; i < 8; i++)
        curr += solve(dp, n, k - 1, r + y[i], c + x[i], x, y);

    return dp[r][c][k] = curr;
}

double knightProbability(int n, int k, int r, int c)
{
    vector<vector<vector<double>>> dp(26, vector<vector<double>>(26, vector<double>(102, 0)));
    vector<double> x = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<double> y = {-1, 1, -2, 2, -2, 2, -1, 1};
    double fav = solve(dp, n, k, r, c, x, y);
    double total = pow(8, k);

    return fav / total;
}

int main()
{

    int n, k, r, c;
    cin >> n >> k >> r >> c;

    double ans = knightProbability(n, k, r, c);
    cout << ans;

    return 0;
}