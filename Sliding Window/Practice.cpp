#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(20001, vector<int>(6, 0));
int mod = 1000000007;

class Solution
{
public:
    int solve(int n, int ind, int last)
    {
        if (dp[n - ind][last] != 0)
            return dp[n - ind][last] % mod;

        if (n == ind)
            return 1;

        if (last == 1)
        {
            return dp[n - ind][1] = solve(n, ind + 1, 2) % mod;
        }

        else if (last == 2)
        {
            return dp[n - ind][2] = (solve(n, ind + 1, 1) % mod +
                                     solve(n, ind + 1, 3) % mod) %
                                    mod;
        }

        else if (last == 3)
        {
            return dp[n - ind][3] = (solve(n, ind + 1, 1) % mod +
                                     solve(n, ind + 1, 2) % mod +
                                     solve(n, ind + 1, 4) % mod +
                                     solve(n, ind + 1, 5) % mod) %
                                    mod;
        }

        else if (last == 4)
        {
            return dp[n - ind][4] = (solve(n, ind + 1, 3) % mod +
                                     solve(n, ind + 1, 5) % mod) %
                                    mod;
        }

        else if (last == 5)
        {
            return dp[n - ind][5] = solve(n, ind + 1, 1) % mod;
        }

        else
        {
            return dp[n - ind][0] = (solve(n, ind + 1, 1) % mod +
                                     solve(n, ind + 1, 2) % mod +
                                     solve(n, ind + 1, 3) % mod +
                                     solve(n, ind + 1, 4) % mod +
                                     solve(n, ind + 1, 5) % mod) %
                                    mod;
        }

        return dp[n][0];
    }

    int countVowelPermutation(int n)
    {
        int ans = 0;
        ans = solve(n, 0, 0);
        return ans;
    }
};