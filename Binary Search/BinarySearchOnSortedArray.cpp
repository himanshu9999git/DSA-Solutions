#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
            return mid;

        else if (v[mid] < target)
            start = mid + 1;

        else if (v[mid] > target)
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int target;
    cin >> target;

    int ans = binarySearch(v, 0, n - 1, target);
    cout << ans;

    return 0;
}