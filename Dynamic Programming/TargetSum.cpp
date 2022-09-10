#include <bits/stdc++.h>
using namespace std;

int TargetSum(int n, int sum, int arr[])
{
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }

    int t[n + 1][range + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;

            if (j == 0)
                t[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];

            else
                t[i][j] = t[i - 1][j];
        }
    }

    vector<pair<int,int>> v;
    for (int i = 0; i < range + 1; i++)
    {
        if (t[n][i])
            v.push_back(make_pair(i,t[n][i]));
    }

    int count = 0;

    for (int i = 0; i < v.size() / 2; i++)
    {
        if(range - 2*v[i].first == sum)
        count += v[i].second;
    }

    return count;
}

int main()
{
    int n,sum;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin>>sum;

    cout << TargetSum(n, sum, arr);

    return 0;
}