#include <bits/stdc++.h>
using namespace std;

vector<int> NearestGreaterToRight(vector<int> arr, int n)
{
    vector<int> v;
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            v.push_back(-1);

        else if (arr[i] < s.top())
            v.push_back(s.top());

        else
        {
            while (!s.empty() && arr[i] >= s.top())
                s.pop();

            if (s.empty())
                v.push_back(-1);

            else if (arr[i] < s.top())
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    return v;
}

void PrintVector(vector<int> arr)
{
    int n = arr.size();

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
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

    vector<int> res(n);
    res = NearestGreaterToRight(arr, n);

    PrintVector(res);

    return 0;
}