// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

#include <bits/stdc++.h>
using namespace std;

int minimumCardPickup(vector<int> &cards)
{
    int n = cards.size();
    unordered_map<int, int> mp;

    int mn = n;
    int i = 0, j = 0;
    bool flag = false;

    while (j < n)
    {
        mp[cards[j]]++;

        if (mp[cards[j]] > 1)
        {
            flag = true;
            while (mp[cards[j]] > 1)
            {
                mp[cards[i]]--;
                i++;
            }
            mn = min(mn, j - i + 2);
        }
        j++;
    }
    if (flag == false)
        return -1;

    return mn;
}

int main()
{

    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    int ans = minimumCardPickup(cards);
    cout << ans;

    return 0;
}