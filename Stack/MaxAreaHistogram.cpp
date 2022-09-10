#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> arr, int n)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            v.push_back(-1);

        else if (arr[i] > s.top().first)
            v.push_back(s.top().second);

        else
        {
            while (!s.empty() && arr[i] <= s.top().first)
                s.pop();

            if (s.empty())
                v.push_back(-1);

            else if (arr[i] > s.top().first)
                v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    return v;
}

vector<int> NSR(vector<int> arr, int n)
{
    vector<int> v;
    stack<pair<int, int>> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            v.push_back(n);

        else if (arr[i] > s.top().first)
            v.push_back(s.top().second);

        else
        {
            while (!s.empty() && arr[i] <= s.top().first)
                s.pop();

            if (s.empty())
                v.push_back(n);

            else if (arr[i] > s.top().first)
                v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    reverse(v.begin(), v.end());
    return v;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> l = NSL(heights, n);
    vector<int> r = NSR(heights, n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int area;
    area = largestRectangleArea(heights);

    cout << area;

    return 0;
}