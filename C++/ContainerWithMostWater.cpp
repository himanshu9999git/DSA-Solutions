#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int mx = 0;

    int l = 0, r = n - 1;
    while (l < r)
    {
        mx = max(mx, (r - l) * min(height[l], height[r]));
        if (height[l] < height[r])
            l++;

        else
            r--;
    }

    return mx;
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

    int ans = maxArea(height);
    cout << ans;

    return 0;
}