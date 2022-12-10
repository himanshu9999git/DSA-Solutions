// 2 sorted arrays
// arr1 = {3, 5};
// arr2 = {6, 7};

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m, n;
    cin >> m;
    cin >> n;

    vector<int> nums1(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    vector<int> nums2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    int i = 0;
    int j = 0;

    vector<int> nums;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            nums.push_back(nums1[i]);
            i++;
        }

        else
        {
            nums.push_back(nums2[j]);
            j++;
        }
    }

    if (j == n)
    {
        while (i < n)
        {
            nums.push_back(nums1[i]);
            i++;
        }
    }

    if (i == m)
    {
        while (j < m)
        {
            nums.push_back(nums2[j]);
            j++;
        }
    }

    if ((m + n) % 2 == 1)
    {
        cout << nums[nums.size() / 2];
    }

    else
    {
        float ans;
        ans = (float)(((float)(nums[nums.size() / 2] + nums[nums.size() / 2 - 1])) / 2);
        cout << ans;
    }

    return 0;
}