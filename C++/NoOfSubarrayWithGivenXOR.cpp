#include <bits/stdc++.h>
using namespace std;

int countXor(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    int xr = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        if (xr == k)
            count++;

        if (mp.find(xr ^ k) != mp.end())
            count += mp[xr ^ k];

        mp[xr]++;
    }
    return count;
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

    int k;
    cin >> k;

    int ans = countXor(arr, k);
    cout << ans;

    return 0;
}