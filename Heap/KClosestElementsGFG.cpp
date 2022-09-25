#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

vector<int> printKClosest(vector<int> arr, int n, int k, int x)
{
    vector<int> ans;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
        v.push_back(make_pair(abs(x - arr[i]), arr[i]));

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < k; i++)
    {
        if (v[i].second == x)
        {
            k++;
            continue;
        }
        ans.push_back(v[i].second);
    }
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

    vector<int> ans = printKClosest(arr, n, k, x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}