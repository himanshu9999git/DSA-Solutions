#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vi vector<int>

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        ll sum = 1;
        sum += (s.at(0) - 'a') * 25;
        sum += (s.at(1) - 'a');

        if (s.at(1) > s.at(0))
            sum--;

        cout << sum << endl;
    }

    return 0;
}