#include <bits/stdc++.h>
using namespace std;

int longestBitonicSequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> dpl(n, 1);
    vector<int> dpr(n, 1);

    for (int i = 1; i < n; i++)
    {
        int mx = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
                mx = max(mx, dpl[j]);
        }
        dpl[i] += mx;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int mx = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[i])
                mx = max(mx, dpr[j]);
        }
        dpr[i] += mx;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dpl[i] + dpr[i] - 1);

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

    int ans = longestBitonicSequence(nums);
    cout << ans;

    return 0;
}