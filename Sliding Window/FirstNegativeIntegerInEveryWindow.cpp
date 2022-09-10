#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(vector<long long> a, long long n, long long k)
{
    vector<long long> v;
    queue<long long> q;

    long long i = 0;
    while (i < k - 1)
    {
        if (a[i] < 0)
            q.push(a[i]);

        i++;
    }

    while (i < n)
    {
        if (a[i] < 0)
            q.push(a[i]);

        if (!q.empty())
        {
            v.push_back(q.front());

            if (a[i - k + 1] == q.front())
                q.pop();
        }
        else
            v.push_back(0);

        i++;
    }

    return v;
}

int main()
{
    long long n, k;
    cin >> n;

    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    vector<long long> v = printFirstNegativeInteger(arr, n, k);

    for (long long i = 0; i < n - k + 1; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}