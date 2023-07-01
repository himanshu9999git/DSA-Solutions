// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    unordered_map<long long, long long> mp;
    int n = tasks.size();

    for (int i = 0; i < n; i++)
    {
        mp[tasks[i]]++;
    }

    int count = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second == 1)
            return -1;

        count += (i->second + 2) / 3;
    }
    return count;
}

int main()
{

    int n;
    cin >> n;

    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i];
    }

    int ans = minimumRounds(tasks);
    cout << ans;

    return 0;
}