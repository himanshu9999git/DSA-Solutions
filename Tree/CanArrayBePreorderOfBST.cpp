#include <bits/stdc++.h>
using namespace std;

int canRepresentBST(int arr[], int n)
{
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < root)
            return 0;

        while (!s.empty() && s.top() < arr[i])
        {
            root = s.top();
            s.pop();
        }
        s.push(arr[i]);
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << endl
         << canRepresentBST(arr, n);

    return 0;
}