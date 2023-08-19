#include <bits/stdc++.h>
using namespace std;

long long getCount(int n)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));

    vector<vector<long long>> mat(10);
    mat[0] = {0, 8};
    mat[1] = {1, 2, 4};
    mat[2] = {1, 2, 3, 5};
    mat[3] = {2, 3, 6};
    mat[4] = {1, 4, 5, 7};
    mat[5] = {2, 4, 5, 6, 8};
    mat[6] = {3, 5, 6, 9};
    mat[7] = {4, 7, 8};
    mat[8] = {5, 7, 8, 9, 0};
    mat[9] = {6, 8, 9};

    for (int j = 0; j <= 9; j++)
        dp[1][j] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (auto k : mat[j])
                dp[i][j] += dp[i - 1][k];
        }
    }

    long long sum = 0;
    for (int j = 0; j <= 9; j++)
        sum += dp[n][j];

    return sum;
}

int main()
{

    int n;
    cin >> n;

    long long ans = getCount(n);
    cout << ans;

    return 0;
}