#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int index = 0;
    int sumt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (gas[i] - cost[i]);
        sumt += (gas[i] - cost[i]);

        if (sumt < 0)
        {
            index = i + 1;
            sumt = 0;
        }
    }

    if (sum < 0)
        return -1;

    return index;
}

int main()
{
    int n;
    cin >> n;

    vector<int> gas(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gas[i];
    }

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int ans = canCompleteCircuit(gas, cost);
    cout << ans;

    return 0;
}