#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> v, int start, int end, int target)
{
    int first = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            first = mid;
            end = mid - 1;
        }

        else if (v[mid] < target)
            start = mid + 1;

        else if (v[mid] > target)
            end = mid - 1;
    }
    return first;
}

int lastOccurence(vector<int> v, int start, int end, int target)
{
    int last = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            last = mid;
            start = mid + 1;
        }

        else if (v[mid] < target)
            start = mid + 1;

        else if (v[mid] > target)
            end = mid - 1;
    }
    return last;
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

    int first = firstOccurence(v, 0, n - 1, target);
    int last = lastOccurence(v, 0, n - 1, target);

    cout << first << endl
         << last;

    return 0;
}