#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> NearestGreaterToRight(vector<int> arr, int n)
{
    vector<pair<int, int>> v;
    stack<pair<int, int>> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            v.push_back(make_pair(-1, -1));

        else if (arr[i] < s.top().first)
            v.push_back(s.top());

        else
        {
            while (!s.empty() && arr[i] > s.top().first)
                s.pop();

            if (s.empty())
                v.push_back(make_pair(-1, -1));

            else if (arr[i] < s.top().first);
                v.push_back(s.top());
        }
        s.push(make_pair(arr[i], i));
    }

    reverse(v.begin(), v.end());
    return v;
}

vector<pair<int, int>> NearestGreaterToLeft(vector<int> arr, int n)
{
    vector<pair<int, int>> v;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            v.push_back(make_pair(-1, -1));

        else if (arr[i] < s.top().first)
            v.push_back(s.top());

        else
        {
            while (!s.empty() && arr[i] > s.top().first)
                s.pop();

            if (s.empty())
                v.push_back(make_pair(-1, -1));

            else if (arr[i] < s.top().first)
                v.push_back(s.top());
        }
        s.push(make_pair(arr[i], i));
    }

    return v;
}