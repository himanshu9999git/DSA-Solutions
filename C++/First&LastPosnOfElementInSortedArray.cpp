#include <bits/stdc++.h>
using namespace std;

void searchPosn(vector<int> &nums, int &l, int &r, int target)
{
    if (l > r)
        return;

    if (nums[l] != target && nums[r] != target)
    {
        l++;
        r--;
        searchPosn(nums, l, r, target);
    }

    else if (nums[l] == target && nums[r] != target)
    {
        r--;
        searchPosn(nums, l, r, target);
    }

    else if (nums[l] != target && nums[r] == target)
    {
        l++;
        searchPosn(nums, l, r, target);
    }

    else if (nums[l] == target && nums[r] == target)
    {
        return;
    }
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    vector<int> v;

    searchPosn(nums, l, r, target);

    if (l > r)
    {
        v.push_back(-1);
        v.push_back(-1);
    }

    else
    {
        v.push_back(l);
        v.push_back(r);
    }
    return v;
}

int main()
{
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> target;

    vector<int> ans;
    ans = searchRange(nums, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}