#include <bits/stdc++.h>
using namespace std;

void heightbalBST(vector<int> &nums, int start, int end, vector<int> &v)
{
    if (start > end)
        return;

    v.push_back(nums[(start + end) / 2]);

    heightbalBST(nums, start, ((start + end) / 2) - 1, v);
    heightbalBST(nums, ((start + end) / 2) + 1, end, v);
}
vector<int> sortedArrayToBST(vector<int> &nums)
{
    vector<int> v;
    heightbalBST(nums, 0, nums.size() - 1, v);
    return v;
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

    vector<int> v = sortedArrayToBST(arr);

    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<endl;
    }
    
    return 0;
}