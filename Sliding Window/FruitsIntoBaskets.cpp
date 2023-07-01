// https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &fruits)
{
    unordered_map<int, int> mp;
    int ans = 0;
    int curr = 0;

    int i = 0;
    int j = 0;

    int n = fruits.size();
    while (j < n)
    {
        mp[fruits[j]]++;
        j++;
        curr++;

        while (mp.size() > 2)
        {
            mp[fruits[i]]--;
            if (mp[fruits[i]] == 0)
                mp.erase(fruits[i]);

            i++;
            curr--;
        }

        ans = max(ans, curr);
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> fruits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }

    int ans = totalFruit(fruits);
    cout << ans;

    return 0;
}