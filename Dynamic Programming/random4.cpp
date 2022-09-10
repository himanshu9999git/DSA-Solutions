#include <bits/stdc++.h>
using namespace std;

int CoinExchange(int n, int sum, int arr[])
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;

            if (i == 0)
                t[i][j] = INT_MAX - 1;
        }
    }
    for (int j = 1; j < sum + 1; j++)
    {
        if (j % arr[0])
            t[1][j] = INT_MAX - 1;

        else
            t[1][j] = j / arr[0];
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = min(1 + t[i][j - arr[i - 1]], t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }
    if (t[n][sum] == 2147483646)
        return -1;

    else
        return t[n][sum];
}

int main()
{
    int n, sum;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> sum;

    cout << CoinExchange(n, sum, arr);

    return 0;
}