#include <bits/stdc++.h>
using namespace std;

int MaxSumSubarray(vector<int> v, int k)
{
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    int mx = sum;
    
    for (int i = 0; i + k < n; i++)
    {
        sum = sum + v[i + k] - v[i];
        mx = max(mx, sum);
    }

    return mx;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int mx = MaxSumSubarray(v, k);
    cout << endl
         << mx;

    return 0;
}