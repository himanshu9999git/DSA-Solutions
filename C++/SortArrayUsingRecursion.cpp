#include <bits/stdc++.h>
using namespace std;

void SortArray(vector<int> &arr, int n)
{
    if(n==0)
    return;
    
    int max = INT_MIN;
    int index;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            index = i;
        }
    }
    
    swap(arr[n-1],arr[index]);
    SortArray(arr, n-1);
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
    SortArray(arr, n);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}