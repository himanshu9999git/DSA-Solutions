#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    vector<pair<int, int>> v;

    int n = arr.size();
    for (int i = 0; i < n; i++)
        v.push_back(make_pair(abs(x - arr[i]), arr[i]));

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < k; i++)
        ans.push_back(v[i].second);

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k, x;
    cin >> k >> x;

    vector<int> ans = findClosestElements(arr, k, x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}