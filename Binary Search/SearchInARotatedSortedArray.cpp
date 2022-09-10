#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int ans;
    int start = 0;
    int end = n - 1;

    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (nums[mid] == nums[end])
        {
            ans = mid;
            break;
        }

        else if (nums[mid] < nums[end])
            end = mid;

        else if (nums[mid] > nums[end])
            start = mid + 1;
    }

    start = 0;
    end = n - 1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (nums[(mid + ans) % n] == target)
            return (mid + ans) % n;

        else if (nums[(mid + ans) % n] < target)
            start = mid + 1;

        else if (nums[(mid + ans) % n] > target)
            end = mid - 1;
    }
    return -1;
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

    int target;
    cin >> target;

    int ans = search(nums, target);
    cout << ans;

    return 0;
}
