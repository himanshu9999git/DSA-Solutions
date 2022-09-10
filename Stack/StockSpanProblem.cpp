#include <bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> arr, int n)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            v.push_back(-1);

        else if (arr[i] < s.top().first)
            v.push_back(s.top().second);

        else
        {
            while (!s.empty() && arr[i] >= s.top().first)
                s.pop();

            if (s.empty())
                v.push_back(-1);

            else if (arr[i] < s.top().first)
                v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = i - v[i];
    }

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
    res = StockSpan(arr, n);

    PrintVector(res);

    return 0;
}