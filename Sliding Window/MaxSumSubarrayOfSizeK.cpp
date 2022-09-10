#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int k, vector<int> &arr, int n)
{
    int i = 0, sum = 0, mx = 0;
    while (i < k)
    {
        sum += arr[i];
        i++;
    }
    mx = max(sum, mx);

    while (i < n)
    {
        sum = sum + arr[i] - arr[i - k];
        mx = max(sum, mx);
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
        cin >> arr[i];

    cin >> k;

    int mx = maximumSumSubarray(k, arr, n);
    cout << mx;

    return 0;
}