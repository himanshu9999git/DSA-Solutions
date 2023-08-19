#include <bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<unordered_map<int, int>> conn(n);
    for (int i = 0; i < roads.size(); i++)
    {
        conn[roads[i][0]][roads[i][1]];
        conn[roads[i][1]][roads[i][0]];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = 0;
            bool flag = false;

            if (conn[i].find(j) != conn[i].end())
                flag = true;

            num += conn[i].size();
            num += conn[j].size();

            if (flag)
                num--;

            ans = max(ans, num);
        }
    }
    return ans;
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<vector<int>> nums(k, vector<int>(2));
    for (int i = 0; i < k; i++)
    {
        cin >> nums[i][0];
        cin >> nums[i][1];
    }

    int ans = maximalNetworkRank(n, nums);
    cout << ans;

    return 0;
}