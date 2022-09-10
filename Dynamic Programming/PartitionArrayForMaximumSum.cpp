#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        long long mx = 0;
        long long mxe = 0;
        for (int j = i; j < min(n, i + k); j++)
        {
            mxe = max(mxe, (long long)arr[j]);
            mx = max(mx, (j - i + 1) * mxe + dp[j + 1]);
        }
        dp[i] = mx;
    }
    return (int)dp[0];
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

    int ans = maxSumAfterPartitioning(arr, k);
    cout << ans;

    return 0;
}