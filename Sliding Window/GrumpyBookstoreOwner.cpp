// https://leetcode.com/problems/grumpy-bookstore-owner/submissions/

#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int ans = 0;
    int sum = 0;
    int n = customers.size();

    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
            sum += customers[i];
    }

    int i = 0;
    int j = 0;

    while (j < minutes - 1)
    {
        if (grumpy[j] == 1)
            sum += customers[j];

        j++;
    }

    while (j < n)
    {
        if (grumpy[j] == 1)
            sum += customers[j];

        ans = max(ans, sum);

        if (grumpy[i] == 1)
            sum -= customers[i];

        i++;
        j++;
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> customers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i];
    }

    vector<int> grumpy(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grumpy[i];
    }

    int minutes;
    cin>>minutes;

    int ans = maxSatisfied(customers, grumpy, minutes);
    cout << ans;

    return 0;
}