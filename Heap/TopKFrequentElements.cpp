#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
        mp[nums[i]]++;

    for (auto i = mp.begin(); i != mp.end(); i++)
        q.push(make_pair(i->second, i->first));

    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    vector<int> ans = topKFrequent(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}