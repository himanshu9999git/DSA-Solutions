#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int mn = INT_MAX;
        int mni = -1;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < mn)
            {
                mn = arr[j];
                mni = j;
            }
        }
        swap(arr[i], arr[mni]);
    }
}

int select(vector<int> &arr, int i)
{
    selectionSort(arr, i);
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

    select(nums, n);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}