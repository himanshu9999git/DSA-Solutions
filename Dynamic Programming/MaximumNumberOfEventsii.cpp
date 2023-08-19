#include <bits/stdc++.h>
using namespace std;

int binarySearch(int index, vector<vector<int>> &events, int target)
{
    int start = index;
    int end = events.size() - 1;
    int ans = -1;
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (events[mid][0] >= target)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int solve(vector<vector<int>> &events, vector<vector<int>> &dp, int i, int k)
{
    if (i >= events.size() || k == 0 || i == -1)
        return 0;

    if (dp[i][k])
        return dp[i][k];

    int index = binarySearch(i + 1, events, events[i][1]);

    int c1 = events[i][2] + solve(events, dp, index, k - 1);
    int c2 = solve(events, dp, i + 1, k);

    return dp[i][k] = max(c1, c2);
}

int maxValue(vector<vector<int>> &events, int k)
{
    int n = events.size();
    sort(events.begin(), events.end());

    for (int i = 0; i < n; i++)
        events[i][0]--;

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    solve(events, dp, 0, k);

    return dp[0][k];
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> events(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> events[i][j];
        }
    }

    int k;
    cin >> k;

    int ans = maxValue(events, k);
    cout << ans;

    return 0;
}
