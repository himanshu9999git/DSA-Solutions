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
            while (!s.empty() && arr[i] < s.top().first)
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
            while (!s.empty() && arr[i] < s.top().first)
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

int MaxAreaHistogram(vector<int> arr, int n)
{
    vector<int> nsr = NSR(arr, n);
    vector<int> nsl = NSL(arr, n);

    int max = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = arr[i] * (nsr[i] - nsl[i] - 1);

        if (max < v[i])
            max = v[i];
    }

    return max;
}

int MaxAreaRectangle(vector<vector<int>> &matrix, int n)
{
    vector<int> v(n, 0);
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 1)
            {
                matrix[i][j] += v[j];
            }
            v[j] = matrix[i][j];
        }
        
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        res[i] = MaxAreaHistogram(matrix[i], n);

        if(max < res[i])
        max = res[i];
    }
    
    return max;
    
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
        
    }

    int area;
    area = MaxAreaRectangle(matrix, n);

    cout << endl
         << area;
         
    return 0;
}