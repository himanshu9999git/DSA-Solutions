#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(vector<int> arr, int n, int k)
{
    int i = 0;
    int sum = 0;
    int mx = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    while (i < n)
    {
        sum += arr[i];

        // if (sum == k)
        //     mx = i + 1;

        if (mp.find(sum - k) != mp.end())
        {
            if (i - mp[sum - k] > mx)
                mx = i - mp[sum - k];
        }

        if (mp.find(sum) == mp.end())
            mp[sum] = i;

        i++;
    }
    return mx;
}

int main()
{
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    int ans = lenOfLongSubarr(arr, n, k);
    cout << ans;

    return 0;
}