#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> right(n, 0);
    vector<int> left(n, 0);

    int mxr = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(mxr, height[i + 1]);
        mxr = right[i];

        if (right[i] <= height[i])
            right[i] = 0;

        else
            right[i] = right[i] - height[i];
    }

    int mxl = height[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(mxl, height[i - 1]);
        mxl = left[i];

        if (left[i] <= height[i])
            left[i] = 0;

        else
            left[i] = left[i] - height[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(right[i], left[i]);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int ans = trap(height);
    cout << ans;

    return 0;
}